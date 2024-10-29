import os
import sys
import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin

""" INSTRUCTIONS

- Install libraries with: pip install requests beautifulsoup4

- Change PDF_FOLDER and CODE_FOLDER x lines below to wherever you wish to download
lecture pdfs, and lecture code files.

  You can use {n} in the name to act as a placeholder as in the n-th lecture.

  Folder path should be given relative to wherever the code is being run.

  If you're running it inside WSL make sure to Unix-style paths to access even non-WSL locations

- Run the script once to see sample usage
"""

PDF_FOLDER = lambda n: '/mnt/d/Notes/notes/CS101/'
CODE_FOLDER = lambda n: f"{n}/"

# * checks for existence in "PDF_BASE_URL/n-html"
# * downloads pdf from "PDF_BASE_URL/n.pdf" as "PDF_DL_DIR/n.pdf"
# * checks for corressponding c,cpp,h,hpp files in "LECTURES_URL/"
# * downloads c,cpp,h,hpp files from "CODE_BASE_URL/n-progs/<filename>.<ext>" as "CODE_DL_DIR/<filename>.<ext>"

PDF_BASE_URL = 'https://www.cse.iitb.ac.in/~cs101/lectures/'
CODE_BASE_URL = 'https://www.cse.iitb.ac.in/~cs101/'
# hidden link i found by creating a raw request (without js exec)
LECTURES_URL = 'https://www.cse.iitb.ac.in/~cs101/lectureList.html'

CODE_FILE_EXTS = ('.c', '.cpp', '.h', '.hpp')

# Check for command-line argument for n
if len(sys.argv) != 2:
    print("Usage: python3 scrape.py <n>\n  n (int, >0): lecture to download")
    sys.exit(1)

# Retrieve lecture number n from command-line arguments
n = int(sys.argv[1])
fmtd_n = f"{n:02}"
assert n > 0

# Fill in placeholders and check if directory exists else create
PDF_FOLDER = PDF_FOLDER(fmtd_n)
CODE_FOLDER = CODE_FOLDER(fmtd_n)

os.makedirs(PDF_FOLDER, exist_ok=True)
os.makedirs(CODE_FOLDER, exist_ok=True)

# Set headers for HTTP request to prevent blocking
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
}

# Step 0: Check if exists
try:
    # Fetch lecture list page
    lecture_response = requests.get(LECTURES_URL, headers=headers)
    lecture_response.raise_for_status()
    lecture_soup = BeautifulSoup(lecture_response.text, 'html.parser')

    found = False

    for link in lecture_soup.find_all('a', href=True):
        href = link['href']
        if href.endswith(f"lectures/{fmtd_n}-html"):
            found = True
    
    if not found:
        print(f"Lecture {fmtd_n} was not found! Exiting.")
        sys.exit(2)

except requests.RequestException as e:
    print(f"Failed to access {LECTURES_URL} to check for existence of lecture {fmtd_n}: {e}")

# Step 1: Download n.pdf into PDF_DL_DIR
pdf_path = os.path.join(PDF_FOLDER, f"{fmtd_n}.pdf")
pdf_url = urljoin(PDF_BASE_URL, f"{fmtd_n}.pdf")
if not os.path.exists(pdf_path):
    try:
        print(f"Downloading {pdf_url}...")
        pdf_response = requests.get(pdf_url, headers=headers, stream=True)
        pdf_response.raise_for_status()
        
        with open(pdf_path, 'wb') as pdf_file:
            for chunk in pdf_response.iter_content(chunk_size=1024):
                if chunk:
                    pdf_file.write(chunk)
        print(f"Downloaded {fmtd_n}.pdf to {pdf_path}")

    except requests.RequestException as e:
        print(f"Failed to download {pdf_url}: {e}")
else:
    print(f"{pdf_path} already exists, skipping download.")
print()

# Step 2: Scrape .cpp links from lecture_url and download files for lecture n
try:
    # Fetch lecture list page
    lecture_response = requests.get(LECTURES_URL, headers=headers)
    lecture_response.raise_for_status()
    lecture_soup = BeautifulSoup(lecture_response.text, 'html.parser')
    
    # Filter code links based on lecture n
    code_files = []
    for link in lecture_soup.find_all('a', href=True):
        href = link['href']
        if href.startswith(f"lectures/{fmtd_n}-progs/") and href.endswith(CODE_FILE_EXTS):
            code_files.append(href)
    
    # Download each code file from the corresponding n-progs folder
    for code_file in code_files:
        code_url = urljoin(CODE_BASE_URL, code_file)
        code_filename = os.path.basename(code_file)
        code_file_path = os.path.join(CODE_FOLDER, code_filename)
        
        if not os.path.exists(code_file_path):
            print(f"Downloading {code_url}...")
            code_response = requests.get(code_url, headers=headers, stream=True)

            # Check for redirection
            if code_response.history:
                print(f"> Redirection occurred for {code_url}:")
                for resp in code_response.history:
                    print(f"> - {resp.status_code} {resp.url}")
                print(f"> Final destination: {code_response.status_code} {code_response.url}")
                print("> Skipping this file!")
                print()
                continue

            code_response.raise_for_status()
            
            # Save each .cpp file
            with open(code_file_path, 'wb') as file:
                for chunk in code_response.iter_content(chunk_size=1024):
                    if chunk:
                        file.write(chunk)
            print(f"Downloaded {code_filename} to {code_file_path}")

        else:
            print(f"{code_file_path} already exists, skipping download.")

        print()

except requests.RequestException as e:
    print(f"Failed to access {LECTURES_URL} or download cpp files: {e}")

print("Downloads completed.")