# Q10. Theory – What is a `.gitignore` File?

## What is a `.gitignore` File?

A **`.gitignore`** file is a configuration file used by Git to specify which files and folders should **not** be tracked or committed to a repository. It helps keep the repository clean by excluding temporary files, compiled output, operating system files, and IDE-specific configuration files that are not required by other developers.

Using a `.gitignore` file:

* Prevents unnecessary files from being committed.
* Keeps the repository organized.
* Reduces repository size.
* Avoids sharing machine-specific or temporary files.

---

## `.gitignore` for an Arduino Project

```gitignore
# -------------------------------------------------
# Arduino Compiled Output Files
# -------------------------------------------------
*.hex
*.elf

# -------------------------------------------------
# Build Folder
# -------------------------------------------------
build/

# -------------------------------------------------
# Visual Studio Code Configuration
# -------------------------------------------------
.vscode/

# -------------------------------------------------
# macOS System Files
# -------------------------------------------------
.DS_Store

# -------------------------------------------------
# Windows System Files
# -------------------------------------------------
Thumbs.db
```

---

## Explanation

| Entry       | Purpose                                      |
| ----------- | -------------------------------------------- |
| `*.hex`     | Ignores compiled Arduino HEX files.          |
| `*.elf`     | Ignores compiled ELF executable files.       |
| `build/`    | Ignores the build output directory.          |
| `.vscode/`  | Ignores Visual Studio Code project settings. |
| `.DS_Store` | Ignores macOS hidden system files.           |
| `Thumbs.db` | Ignores Windows thumbnail cache files.       |

---

## Summary

A `.gitignore` file ensures that only important source files are tracked in the repository while automatically excluding generated files, operating system files, and IDE configuration folders. This makes collaboration easier and keeps the project repository clean and professional.
