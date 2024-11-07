# CS101

My submission/practice files for the fall'24 semester course, IITB.

Compile files using `s++` as:
```bash
s++ <filename>
```

Or, alternatively pass the following arguments to `g++` (assuming `X11` and other dependencies installed properly using the [script](./download-and-install-s++.sh))
```bash
-Wall /<install-dir>/simplecpp/lib/libsprite.a -I/<install-dir>/simplecpp/include -I/usr/include/X11 -L/usr/X11R6/lib -lX11 -std=c++11
```

If installing using the script, `<install-dir>` is `/home/<username>`

## `simplecpp`
[simplecpp](https://www.cse.iitb.ac.in/~ranade/simplecpp/)

[simplecpp.tar](https://www.cse.iitb.ac.in/~ranade/simplecpp/simplecpp.tar) (or use local version, as on 04/08/2024)

[Download instructions](https://docs.google.com/document/d/1toxyF__JIN6tsOWcA2UbUCIRsprTC6agWBfGFYo8tUw/edit)

[Install script](https://docs.google.com/document/d/1toxyF__JIN6tsOWcA2UbUCIRsprTC6agWBfGFYo8tUw/edit)

[Local Version](./download-and-install-s++.sh)

- I am using WSL for installing this

### Sys Info
```
OS: Ubuntu 22.04.4 LTS on Windows 10 x86_64
Kernel: 5.15.153.1-microsoft-standard-WSL2
```

### Fix

Update `sudo apt update -y && sudo apt upgrade -y`

Install packages `sudo apt install neofetch systemd x11-apps g++ libx11-dev make -y`

Run `download-and-install-s++.sh`
(as on 4/8/2024)

Restart

Works!

_No need to clone [source](https://github.com/adi-g15/simplecpp) and `sudo make install`, it doesn't work!_

### Effect
Installs `s++` and `runs++` in ~/bin and adds it to path, by adding `source ~/.profile_spp`: `export PATH"=$HOME/bin:$PATH"`

### Integrating VS Code

Run `code .` in WSL. It will install required packages. WOrks fine.

For code completion, in `/path/to/folder/.vscode/c_cpp_properties` use (replace username):

```json
{
  "configurations": [
    {
      "name": "linux-gcc-x64",
      "includePath": ["${workspaceFolder}/**"],
      "compilerPath": "/usr/bin/g++", // <===
      "cStandard": "${default}",
      "cppStandard": "c++11", // <===
      "intelliSenseMode": "linux-gcc-x64",
      "compilerArgs": [
        // <===
        "-Wall /<install-dir>/simplecpp/lib/libsprite.a",
        "-I/<install-dir>/simplecpp/include",
        "-I/usr/include/X11",
        "-L/usr/X11R6/lib",
        "-lX11",
        "-std=c++11"
      ]
    }
  ],
  "version": 4
}
```

### TROUBLESHOOTING

https://learn.microsoft.com/en-us/windows/wsl/tutorials/gui-apps
https://github.com/microsoft/wslg/wiki/Diagnosing-%22cannot-open-display%22-type-issues-with-WSLg
