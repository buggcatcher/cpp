
### Exercise 01: My Awesome Phonebook

**Turn-in directory:** `01/`  
**Files to turn in:** `Makefile`, `*.cpp`, `*.{h,hpp}`  
**Forbidden functions:** None  
**Executable:** Give it a relevant name (e.g., `phonebook`)

## Goal

Create a tiny 80s-style phonebook CLI that manages up to 8 contacts without any dynamic allocation. Everything lives inside two classes: `PhoneBook` (owns the fixed-size array) and `Contact` (holds a single entry).

## Class Requirements

### PhoneBook
- Contains an array of contacts
- Maximum of 8 contacts; adding a 9th overwrites the oldest entry
- No dynamic allocation is allowed

### Contact
- Represents a single phonebook contact

### Access Rules
- Keep always-internal details `private`
- Expose only what must be used externally as `public`
- Instantiate the phonebook as an instance of `PhoneBook`
- Each contact is an instance of `Contact`

## Program Flow

- On startup the phonebook is empty
- The prompt accepts only three commands: `ADD`, `SEARCH`, `EXIT`
- Any other input is ignored
- After each valid command, prompt again until `EXIT` terminates (contacts are lost on exit)

## Commands

### ADD
- Prompt for all fields: first name, last name, nickname, phone number, darkest secret
- No field may be empty
- After all fields are provided, store the contact (overwriting the oldest if already at 8 entries)

### SEARCH
- List saved contacts as a table with 4 right-aligned columns: index, first name, last name, nickname
- Each column is 10 characters wide, separated by `|`
- If text exceeds 10 characters, truncate and replace the last character with `.`
- After listing, prompt for an index; if invalid, handle gracefully; otherwise, print the full contact (one field per line)

### EXIT
- Quit the program; contacts are not persisted

## I/O Notes

- Use standard I/O streams (`iostream`, `iomanip`, `string`)
- Helpful references:
  - http://www.cplusplus.com/reference/string/string/
  - http://www.cplusplus.com/reference/iomanip/

## Build and Run

1. In `01/`, ensure `Makefile` builds the executable (no dynamic allocation required)
2. Run `make` to build
3. Execute `./phonebook` (or the chosen name) and interact via the commands above

---


