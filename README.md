# Privacy+

**Privacy+** is a lightweight, zero-dependency encryption and decryption tool written entirely in C. Designed for high-stakes environments—such as protests, network crackdowns, government surveillance, military field operations, and machine-level communication—it transforms plaintext messages and `.txt` files into unreadable ciphertext using ASCII-shifting mathematical equations.

---

## Key Features

* **Zero Installation Required:** Runs directly via the standalone `.exe` file on Windows—no compiler or external libraries needed.
* **Direct Message Encryption:** Encrypts user-inputted text messages (up to 40 characters) in real time by shifting ASCII values via a mathematical formula.
* **Direct Message Decryption:** Reverses the mathematical equation to restore encrypted messages back to readable plaintext.
* **`.txt` File Encryption:** Reads a target file (e.g., `notes.txt`) line-by-line (up to 250 characters per line) and outputs the encrypted content to `encrypted_notes.txt`.
* **`.txt` File Decryption:** Processes encrypted `.txt` files line-by-line (up to 250 characters per line) and restores the original text into `decrypt_filename.txt`.
* **Menu-Driven CLI:** Simple 5-option terminal interface built for speed and reliability.

---

## Repository Structure

```text
privacy-plus/
├── main.c          # Core C source code
├── privacy+.exe    # Standalone Windows executable (ready to run)
├── .gitignore      # Git ignore rules
└── README.md       # Project documentation
```

---

## Getting Started

### Quick Run (OS-Independent, No Compiler or Git Needed)
You do **not** need GCC, Git, or any development tools installed to use Privacy+.

1. **Download the program:**
   * **Single File:** Click on **`privacy+.exe`** in the file list above, then click the **Download raw file** button (downward arrow icon) on the top right.
   * **Full Folder:** Click the green **`<> Code`** button at the top of this page, select **Download ZIP**, and extract the folder.
2. **Run Privacy+:**
   * Double-click **`privacy+.exe`** to launch the terminal interface immediately.
   * *(Note: If Windows Defender SmartScreen shows a warning because the app is unsigned, click **More info** → **Run anyway**.)*

*(Optional)* **Building from Source (Linux/macOS or custom builds):**
If you want to modify `privacy+.c` or clone the repo and compile it using any standard C compiler:
```bash
git clone https://github.com
cd privacy-plus
gcc privacy+.c -o privacy+
./privacy+

```
---
## Usage
Once launched, choose from the 5 available menu options:

1. **Encrypt a Message:** Enter a string (max 40 characters) to immediately view its encrypted output.
2. **Decrypt a Message:** Paste an encrypted string to decode it back to plaintext.
3. **Encrypt a `.txt` File:** Enter the exact filename (e.g., `secret.txt`). The program generates `encrypted_secret.txt`. *(Make sure the `.txt` file is in the same folder as the `.exe`.)*
4. **Decrypt a `.txt` File:** Enter the encrypted filename (e.g., `encrypted_secret.txt`). The program generates `decrypt_secret.txt`.
5. **Exit:** Safely terminates the program.

---

## Future Plans & Roadmap

Privacy+ is actively evolving from a foundational prototype into a resilient, field-ready security tool. Below is our development roadmap addressing current architectural limitations:

| Priority | Feature / Upgrade | Current Limitation | Planned Implementation |
| :--- | :--- | :--- | :--- |
| **High** | **Dynamic User-Defined Keys** | Uses a static, hardcoded mathematical equation for ASCII shifting. | Allow users to input their own custom encryption/decryption keys, supported by an in-app **Key Creation Guideline** for stronger security. |
| **High** | **Dynamic Memory Management** | File processing uses a fixed buffer of 250 characters per line. | Replace static arrays with dynamic heap allocation (`malloc` / `realloc` / `free`) to process lines of any length without truncation or buffer overflow. |
| **High** | **Image Encryption & Decryption** | Only supports text-based data (CLI messages and `.txt` files). | Implement binary/pixel-level byte manipulation (`rb`/`wb` file modes) to securely encrypt and decrypt image files (e.g., `.jpg`, `.png`, `.bmp`) for visual evidence protection. |  
| **Medium** | **Expanded Message Capacity** | Direct CLI message input is capped at 40 characters. | Increase the direct message input limit from **40 characters to 250 characters** for fuller tactical/emergency communication. |
| **Medium** | **Multi-Format File Support** | Restricted exclusively to `.txt` files. | Extend file handling to support additional file types (e.g., `.pdf`,`.doc`,`.csv`, `.log`, `.json` and raw binary files). |

### Upcoming Milestones
- [ ] **v1.1 — Expanded Message Buffer:** Upgrade direct CLI message limit from 40 to 250 characters.
- [ ] **v1.2 — Dynamic Memory Engine:** Refactor file I/O using `malloc`/`realloc` to eliminate the 250-character line cap.
- [ ] **v2.0 — Dynamic Key Architecture:** Replace the static equation with user-defined keys and display built-in key strength guidelines before encryption.
- [ ] **v2.1 — Universal File Support:** Enable byte-level encryption/decryption for non-`.txt` file extensions.


---


## Contribution
* **Md. Fahim Hosain**.
* **Chowdhury Mohammed Haleem**.
* **Md Moaaz Mosatafa Chawdhury**.
* **Protik Kumar Datta**.
<br><br><i>University of Frontier Technology, Bangladesh</i>


## Disclaimer

This tool is built for class project and for educational purposes, lightweight obfuscation, and offline/air-gapped communication scenarios. Because the current version uses a static mathematical equation, it should not yet be relied upon as a replacement for audited, industry-standard cryptographic protocols (such as AES-256 or PGP) when facing advanced cryptanalysis.

## License

This project is open-source and available under the [MIT License](LICENSE).

