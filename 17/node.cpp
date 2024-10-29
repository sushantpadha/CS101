<!DOCTYPE html><html lang="en" class="h-100"><head>
    <meta charset="utf-8">
    <title>Department of Computer Science and Engineering. IIT Bombay</title>
    <base href="/">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="icon" type="image/x-icon" href="favicon.ico">
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link rel="preconnect" href="https://fonts.googleapis.com">

    <!-- <link
      href="https://fonts.googleapis.com/css2?family=Inter:wght@200;300;400;500;600;700&display=swap"
      rel="preload"
      as="style"
    /> -->
    <!-- <link
      href="https://fonts.googleapis.com/icon?family=Material+Icons"
      rel="stylesheet"
    /> -->
    <!-- <link
      href="https://fonts.googleapis.com/css2?family=Varela+Round&display=swap"
      rel="preload"
      as="style"
    /> -->
    <!-- <link
      href="https://fonts.googleapis.com/css2?family=Source+Sans+Pro&display=swap"
      rel="preload" 
      as="style"
    /> -->
    <!-- <link
      rel="stylesheet"
      href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.css"
    /> -->
    <script>
      document.addEventListener('DOMContentLoaded', function () {
        var currentUrl = window.location.href
        var hashIndex = currentUrl.indexOf('#/')
        if (hashIndex !== -1) {
          var newUrl =
            currentUrl.substring(0, hashIndex) +
            currentUrl.substring(hashIndex + 2)
          window.location.replace(newUrl)
        }
      })
    </script>
  <style>:root{--surface-a:#ffffff;--surface-b:#fafafa;--surface-c:rgba(0,0,0,.04);--surface-d:rgba(0,0,0,.12);--surface-e:#ffffff;--surface-f:#ffffff;--text-color:rgba(0, 0, 0, .87);--text-color-secondary:rgba(0, 0, 0, .6);--primary-color:#3F51B5;--primary-color-text:#ffffff;--font-family:Roboto, Helvetica Neue Light, Helvetica Neue, Helvetica, Arial, Lucida Grande, sans-serif;--surface-0:#ffffff;--surface-50:#FAFAFA;--surface-100:#F5F5F5;--surface-200:#EEEEEE;--surface-300:#E0E0E0;--surface-400:#BDBDBD;--surface-500:#9E9E9E;--surface-600:#757575;--surface-700:#616161;--surface-800:#424242;--surface-900:#212121;--gray-50:#FAFAFA;--gray-100:#F5F5F5;--gray-200:#EEEEEE;--gray-300:#E0E0E0;--gray-400:#BDBDBD;--gray-500:#9E9E9E;--gray-600:#757575;--gray-700:#616161;--gray-800:#424242;--gray-900:#212121;--content-padding:1rem;--inline-spacing:.5rem;--border-radius:4px;--surface-ground:#fafafa;--surface-section:#ffffff;--surface-card:#ffffff;--surface-overlay:#ffffff;--surface-border:rgba(0,0,0,.12);--surface-hover:rgba(0,0,0,.04);--maskbg:rgba(0, 0, 0, .32);--focus-ring:none}@font-face{font-family:Roboto;font-style:normal;font-weight:400;src:local("Roboto"),local("Roboto-Regular"),url(roboto-v20-latin-ext_latin-regular.5c59b24786083ffe.woff2) format("woff2"),url(roboto-v20-latin-ext_latin-regular.c9064c1abfc45804.woff) format("woff")}@font-face{font-family:Roboto;font-style:normal;font-weight:500;src:local("Roboto Medium"),local("Roboto-Medium"),url(roboto-v20-latin-ext_latin-500.de270e01b582cd35.woff2) format("woff2"),url(roboto-v20-latin-ext_latin-500.4ce802079c5e2843.woff) format("woff")}@font-face{font-family:Roboto;font-style:normal;font-weight:700;src:local("Roboto Bold"),local("Roboto-Bold"),url(roboto-v20-latin-ext_latin-700.fea1ca242b09ae4c.woff2) format("woff2"),url(roboto-v20-latin-ext_latin-700.c5993c4d788e3ff6.woff) format("woff")}*{box-sizing:border-box}:root{--blue-50:#f4fafe;--blue-100:#cae6fc;--blue-200:#a0d2fa;--blue-300:#75bef8;--blue-400:#4baaf5;--blue-500:#2196f3;--blue-600:#1c80cf;--blue-700:#1769aa;--blue-800:#125386;--blue-900:#0d3c61;--green-50:#f7faf5;--green-100:#dbe8cf;--green-200:#bed6a9;--green-300:#a1c384;--green-400:#85b15e;--green-500:#689f38;--green-600:#588730;--green-700:#496f27;--green-800:#39571f;--green-900:#2a4016;--yellow-50:#fffcf5;--yellow-100:#fef0cd;--yellow-200:#fde4a5;--yellow-300:#fdd87d;--yellow-400:#fccc55;--yellow-500:#fbc02d;--yellow-600:#d5a326;--yellow-700:#b08620;--yellow-800:#8a6a19;--yellow-900:#644d12;--cyan-50:#f2fcfd;--cyan-100:#c2eff5;--cyan-200:#91e2ed;--cyan-300:#61d5e4;--cyan-400:#30c9dc;--cyan-500:#00bcd4;--cyan-600:#00a0b4;--cyan-700:#008494;--cyan-800:#006775;--cyan-900:#004b55;--pink-50:#fef4f7;--pink-100:#fac9da;--pink-200:#f69ebc;--pink-300:#f1749e;--pink-400:#ed4981;--pink-500:#e91e63;--pink-600:#c61a54;--pink-700:#a31545;--pink-800:#801136;--pink-900:#5d0c28;--indigo-50:#f6f7fc;--indigo-100:#d5d9ef;--indigo-200:#b3bae2;--indigo-300:#919cd5;--indigo-400:#707dc8;--indigo-500:#4e5fbb;--indigo-600:#42519f;--indigo-700:#374383;--indigo-800:#2b3467;--indigo-900:#1f264b;--teal-50:#f2faf9;--teal-100:#c2e6e2;--teal-200:#91d2cc;--teal-300:#61beb5;--teal-400:#30aa9f;--teal-500:#009688;--teal-600:#008074;--teal-700:#00695f;--teal-800:#00534b;--teal-900:#003c36;--orange-50:#fffaf2;--orange-100:#ffe6c2;--orange-200:#ffd391;--orange-300:#ffbf61;--orange-400:#ffac30;--orange-500:#ff9800;--orange-600:#d98100;--orange-700:#b36a00;--orange-800:#8c5400;--orange-900:#663d00;--bluegray-50:#f7f9f9;--bluegray-100:#d9e0e3;--bluegray-200:#bbc7cd;--bluegray-300:#9caeb7;--bluegray-400:#7e96a1;--bluegray-500:#607d8b;--bluegray-600:#526a76;--bluegray-700:#435861;--bluegray-800:#35454c;--bluegray-900:#263238;--purple-50:#faf4fb;--purple-100:#e7cbec;--purple-200:#d4a2dd;--purple-300:#c279ce;--purple-400:#af50bf;--purple-500:#9c27b0;--purple-600:#852196;--purple-700:#6d1b7b;--purple-800:#561561;--purple-900:#3e1046;--red-50:#fef6f5;--red-100:#fcd2cf;--red-200:#faaea9;--red-300:#f88a82;--red-400:#f6675c;--red-500:#f44336;--red-600:#cf392e;--red-700:#ab2f26;--red-800:#86251e;--red-900:#621b16;--primary-50:#f5f6fb;--primary-100:#d1d5ed;--primary-200:#acb4df;--primary-300:#8893d1;--primary-400:#6372c3;--primary-500:#3f51b5;--primary-600:#36459a;--primary-700:#2c397f;--primary-800:#232d64;--primary-900:#192048}@charset "UTF-8";:root{--surface-a:#ffffff;--surface-b:#efefef;--surface-c:#e9ecef;--surface-d:#dee2e6;--surface-e:#ffffff;--surface-f:#ffffff;--text-color:#212529;--text-color-secondary:#6c757d;--primary-color:#007bff;--primary-color-text:#ffffff;--font-family:-apple-system, BlinkMacSystemFont, Segoe UI, Roboto, Helvetica, Arial, sans-serif, Apple Color Emoji, Segoe UI Emoji, Segoe UI Symbol;--surface-0:#ffffff;--surface-50:#f9fafb;--surface-100:#f8f9fa;--surface-200:#e9ecef;--surface-300:#dee2e6;--surface-400:#ced4da;--surface-500:#adb5bd;--surface-600:#6c757d;--surface-700:#495057;--surface-800:#343a40;--surface-900:#212529;--gray-50:#f9fafb;--gray-100:#f8f9fa;--gray-200:#e9ecef;--gray-300:#dee2e6;--gray-400:#ced4da;--gray-500:#adb5bd;--gray-600:#6c757d;--gray-700:#495057;--gray-800:#343a40;--gray-900:#212529;--content-padding:1.25rem;--inline-spacing:.5rem;--border-radius:4px;--surface-ground:#efefef;--surface-section:#ffffff;--surface-card:#ffffff;--surface-overlay:#ffffff;--surface-border:#dee2e6;--surface-hover:#e9ecef;--maskbg:rgba(0, 0, 0, .4);--focus-ring:0 0 0 .2rem rgba(38, 143, 255, .5)}*{box-sizing:border-box}:root{--blue-50:#f3f8ff;--blue-100:#c5dcff;--blue-200:#97c1fe;--blue-300:#69a5fe;--blue-400:#3b8afd;--blue-500:#0d6efd;--blue-600:#0b5ed7;--blue-700:#094db1;--blue-800:#073d8b;--blue-900:#052c65;--green-50:#f4f9f6;--green-100:#c8e2d6;--green-200:#9ccbb5;--green-300:#70b595;--green-400:#459e74;--green-500:#198754;--green-600:#157347;--green-700:#125f3b;--green-800:#0e4a2e;--green-900:#0a3622;--yellow-50:#fffcf3;--yellow-100:#fff0c3;--yellow-200:#ffe494;--yellow-300:#ffd965;--yellow-400:#ffcd36;--yellow-500:#ffc107;--yellow-600:#d9a406;--yellow-700:#b38705;--yellow-800:#8c6a04;--yellow-900:#664d03;--cyan-50:#f3fcfe;--cyan-100:#c5f2fb;--cyan-200:#97e8f9;--cyan-300:#69def6;--cyan-400:#3bd4f3;--cyan-500:#0dcaf0;--cyan-600:#0baccc;--cyan-700:#098da8;--cyan-800:#076f84;--cyan-900:#055160;--pink-50:#fdf5f9;--pink-100:#f5cee1;--pink-200:#eda7ca;--pink-300:#e681b3;--pink-400:#de5a9b;--pink-500:#d63384;--pink-600:#b62b70;--pink-700:#96245c;--pink-800:#761c49;--pink-900:#561435;--indigo-50:#f7f3fe;--indigo-100:#dac6fc;--indigo-200:#bd98f9;--indigo-300:#a06bf7;--indigo-400:#833df4;--indigo-500:#6610f2;--indigo-600:#570ece;--indigo-700:#470ba9;--indigo-800:#380985;--indigo-900:#290661;--teal-50:#f4fcfa;--teal-100:#c9f2e6;--teal-200:#9fe8d2;--teal-300:#75debf;--teal-400:#4ad3ab;--teal-500:#20c997;--teal-600:#1bab80;--teal-700:#168d6a;--teal-800:#126f53;--teal-900:#0d503c;--orange-50:#fff9f3;--orange-100:#ffe0c7;--orange-200:#fec89a;--orange-300:#feaf6d;--orange-400:#fd9741;--orange-500:#fd7e14;--orange-600:#d76b11;--orange-700:#b1580e;--orange-800:#8b450b;--orange-900:#653208;--bluegray-50:#f8f9fb;--bluegray-100:#e0e4ea;--bluegray-200:#c7ced9;--bluegray-300:#aeb9c8;--bluegray-400:#95a3b8;--bluegray-500:#7c8ea7;--bluegray-600:#69798e;--bluegray-700:#576375;--bluegray-800:#444e5c;--bluegray-900:#323943;--purple-50:#f8f6fc;--purple-100:#dcd2f0;--purple-200:#c1aee4;--purple-300:#a68ad9;--purple-400:#8a66cd;--purple-500:#6f42c1;--purple-600:#5e38a4;--purple-700:#4e2e87;--purple-800:#3d246a;--purple-900:#2c1a4d;--red-50:#fdf5f6;--red-100:#f7cfd2;--red-200:#f0a8af;--red-300:#e9828c;--red-400:#e35b68;--red-500:#dc3545;--red-600:#bb2d3b;--red-700:#9a2530;--red-800:#791d26;--red-900:#58151c;--primary-50:#f2f8ff;--primary-100:#c2dfff;--primary-200:#91c6ff;--primary-300:#61adff;--primary-400:#3094ff;--primary-500:#007bff;--primary-600:#0069d9;--primary-700:#0056b3;--primary-800:#00448c;--primary-900:#003166}:root{--fa-style-family-classic:"Font Awesome 6 Free";--fa-font-solid:normal 900 1em/1 "Font Awesome 6 Free"}@font-face{font-family:"Font Awesome 6 Free";font-style:normal;font-weight:900;font-display:block;src:url(fa-solid-900.ce4938a30389d90a.woff2) format("woff2"),url(fa-solid-900.081655f2111aa667.ttf) format("truetype")}:root{--fa-style-family-classic:"Font Awesome 6 Free";--fa-font-regular:normal 400 1em/1 "Font Awesome 6 Free"}@font-face{font-family:"Font Awesome 6 Free";font-style:normal;font-weight:400;font-display:block;src:url(fa-regular-400.f386b6b7c6bf65a5.woff2) format("woff2"),url(fa-regular-400.a937b755f79cb30d.ttf) format("truetype")}:root{--fa-style-family-brands:"Font Awesome 6 Brands";--fa-font-brands:normal 400 1em/1 "Font Awesome 6 Brands"}@font-face{font-family:"Font Awesome 6 Brands";font-style:normal;font-weight:400;font-display:block;src:url(fa-brands-400.e465758e13df1d72.woff2) format("woff2"),url(fa-brands-400.8bf6ccf0176a7567.ttf) format("truetype")}@font-face{font-family:Inter;src:url(Inter-Thin.2f65a53be9326f5f.woff2) format("woff2"),url(Inter-Thin.643b63b9b8b7c71f.woff) format("woff");font-weight:100;font-style:normal;font-display:swap}@font-face{font-family:Inter;src:url(Inter-Bold.1d8ba97e4a4812eb.woff2) format("woff2"),url(Inter-Bold.37e983f687369185.woff) format("woff");font-weight:700;font-style:normal;font-display:swap}@font-face{font-family:Inter;src:url(Inter-Regular.22a8d8ea4117e2a2.woff2) format("woff2"),url(Inter-Regular.328d32e5eaf8b216.woff) format("woff");font-weight:400;font-style:normal;font-display:swap}@font-face{font-family:Inter;src:url(Inter-Black.b67be8bb4f9f4845.woff2) format("woff2"),url(Inter-Black.274173eacedde9d0.woff) format("woff");font-weight:900;font-style:normal;font-display:swap}:root{--mdb-blue:#0d6efd;--mdb-indigo:#6610f2;--mdb-purple:#6f42c1;--mdb-pink:#d63384;--mdb-red:#dc3545;--mdb-orange:#fd7e14;--mdb-yellow:#ffc107;--mdb-green:#198754;--mdb-teal:#20c997;--mdb-cyan:#0dcaf0;--mdb-white:#fff;--mdb-gray:#757575;--mdb-gray-dark:#4f4f4f;--mdb-gray-100:#f5f5f5;--mdb-gray-200:#eeeeee;--mdb-gray-300:#e0e0e0;--mdb-gray-400:#bdbdbd;--mdb-gray-500:#9e9e9e;--mdb-gray-600:#757575;--mdb-gray-700:#616161;--mdb-gray-800:#4f4f4f;--mdb-gray-900:#262626;--mdb-primary:#1266f1;--mdb-secondary:#b23cfd;--mdb-success:#00b74a;--mdb-info:#39c0ed;--mdb-warning:#ffa900;--mdb-danger:#f93154;--mdb-light:#fbfbfb;--mdb-dark:#262626;--mdb-white:#fff;--mdb-black:#000;--mdb-primary-rgb:18, 102, 241;--mdb-secondary-rgb:178, 60, 253;--mdb-success-rgb:0, 183, 74;--mdb-info-rgb:57, 192, 237;--mdb-warning-rgb:255, 169, 0;--mdb-danger-rgb:249, 49, 84;--mdb-light-rgb:251, 251, 251;--mdb-dark-rgb:38, 38, 38;--mdb-white-rgb:255, 255, 255;--mdb-black-rgb:0, 0, 0;--mdb-body-color-rgb:79, 79, 79;--mdb-body-bg-rgb:255, 255, 255;--mdb-font-sans-serif:system-ui, -apple-system, "Segoe UI", Roboto, "Helvetica Neue", Arial, "Noto Sans", "Liberation Sans", sans-serif, "Apple Color Emoji", "Segoe UI Emoji", "Segoe UI Symbol", "Noto Color Emoji";--mdb-font-monospace:SFMono-Regular, Menlo, Monaco, Consolas, "Liberation Mono", "Courier New", monospace;--mdb-gradient:linear-gradient(180deg, rgba(255, 255, 255, .15), rgba(255, 255, 255, 0));--mdb-body-font-family:var(--mdb-font-roboto);--mdb-body-font-size:1rem;--mdb-body-font-weight:400;--mdb-body-line-height:1.6;--mdb-body-color:#4f4f4f;--mdb-body-bg:#fff}*,*:before,*:after{box-sizing:border-box}@media (prefers-reduced-motion: no-preference){:root{scroll-behavior:smooth}}body{margin:0;font-family:var(--mdb-body-font-family);font-size:var(--mdb-body-font-size);font-weight:var(--mdb-body-font-weight);line-height:var(--mdb-body-line-height);color:var(--mdb-body-color);text-align:var(--mdb-body-text-align);background-color:var(--mdb-body-bg);-webkit-text-size-adjust:100%;-webkit-tap-highlight-color:rgba(0,0,0,0)}.h-100{height:100%!important}:root{--mdb-font-roboto:"Roboto", sans-serif;--mdb-bg-opacity:1}body{font-family:var(--mdb-font-roboto);line-height:1.6;color:#4f4f4f}:root{--darkBlue:#004f9f;--lightBlue:#7db9f5;--lightestBlue:#e8f5ff;--grey:#b8c0c7;--darkGrey:#585858;--darkestGrey:#252424;--lightGrey:#e1e7ec;--lightBrightGrey:#fafafa;--brightGrey:#f4f1f1;--mediumBrown:#dbdbdb;--lightBrown:#f4f1f1;--white:#fff;--black:#000000}@charset "UTF-8";:root{--mdb-blue:#0d6efd;--mdb-indigo:#6610f2;--mdb-purple:#6f42c1;--mdb-pink:#d63384;--mdb-red:#dc3545;--mdb-orange:#fd7e14;--mdb-yellow:#ffc107;--mdb-green:#198754;--mdb-teal:#20c997;--mdb-cyan:#0dcaf0;--mdb-white:#fff;--mdb-gray:#757575;--mdb-gray-dark:#4f4f4f;--mdb-gray-100:#f5f5f5;--mdb-gray-200:#eeeeee;--mdb-gray-300:#e0e0e0;--mdb-gray-400:#bdbdbd;--mdb-gray-500:#9e9e9e;--mdb-gray-600:#757575;--mdb-gray-700:#616161;--mdb-gray-800:#4f4f4f;--mdb-gray-900:#262626;--mdb-primary:#1266f1;--mdb-secondary:#b23cfd;--mdb-success:#00b74a;--mdb-info:#39c0ed;--mdb-warning:#ffa900;--mdb-danger:#f93154;--mdb-light:#fbfbfb;--mdb-dark:#262626;--mdb-white:#fff;--mdb-black:#000;--mdb-primary-rgb:18, 102, 241;--mdb-secondary-rgb:178, 60, 253;--mdb-success-rgb:0, 183, 74;--mdb-info-rgb:57, 192, 237;--mdb-warning-rgb:255, 169, 0;--mdb-danger-rgb:249, 49, 84;--mdb-light-rgb:251, 251, 251;--mdb-dark-rgb:38, 38, 38;--mdb-white-rgb:255, 255, 255;--mdb-black-rgb:0, 0, 0;--mdb-body-color-rgb:79, 79, 79;--mdb-body-bg-rgb:255, 255, 255;--mdb-font-sans-serif:system-ui, -apple-system, "Segoe UI", Roboto, "Helvetica Neue", Arial, "Noto Sans", "Liberation Sans", sans-serif, "Apple Color Emoji", "Segoe UI Emoji", "Segoe UI Symbol", "Noto Color Emoji";--mdb-font-monospace:SFMono-Regular, Menlo, Monaco, Consolas, "Liberation Mono", "Courier New", monospace;--mdb-gradient:linear-gradient(180deg, rgba(255, 255, 255, .15), rgba(255, 255, 255, 0));--mdb-body-font-family:var(--mdb-font-roboto);--mdb-body-font-size:1rem;--mdb-body-font-weight:400;--mdb-body-line-height:1.6;--mdb-body-color:#4f4f4f;--mdb-body-bg:#fff}*,*:before,*:after{box-sizing:border-box}@media (prefers-reduced-motion: no-preference){:root{scroll-behavior:smooth}}body{margin:0;font-family:var(--mdb-body-font-family);font-size:var(--mdb-body-font-size);font-weight:var(--mdb-body-font-weight);line-height:var(--mdb-body-line-height);color:var(--mdb-body-color);text-align:var(--mdb-body-text-align);background-color:var(--mdb-body-bg);-webkit-text-size-adjust:100%;-webkit-tap-highlight-color:rgba(0,0,0,0)}.h-100{height:100%!important}:root{--mdb-font-roboto:"Roboto", sans-serif;--mdb-bg-opacity:1}body{font-family:var(--mdb-font-roboto);line-height:1.6;color:#4f4f4f}body{font-family:Inter,sans-serif!important}</style><link rel="stylesheet" href="/styles.25c4f5ce470fcb07.css" media="print" onload="this.media='all'"><noscript><link rel="stylesheet" href="/styles.25c4f5ce470fcb07.css"></noscript></head>
  <body class="h-100">
    <app-root> </app-root>
  <script src="/runtime.2e9cb1e6a10a95c3.js" type="module"></script><script src="/polyfills.0db5713cfe535c5f.js" type="module"></script><script src="/scripts.c9518b18242d7ffd.js" defer></script><script src="/main.d512bdd6cf7af9b1.js" type="module"></script>

</body></html>