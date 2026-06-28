# Q9. Theory – Difference Between `git pull`, `git fetch`, and `git clone`

## 1. `git clone`

**Purpose:**
Creates a complete copy of a remote repository on your local computer, including all files, branches, and commit history.

**When to use:**
Use `git clone` when you are working with a repository for the first time and need to download it from GitHub.

**Example:**

```bash
git clone https://github.com/username/iot-summer-school-2026.git
```

---

## 2. `git fetch`

**Purpose:**
Downloads the latest changes from the remote repository without merging them into your current branch.

**When to use:**
Use `git fetch` when you want to review updates from the remote repository before deciding whether to merge them.

**Example:**

```bash
git fetch origin
```

---

## 3. `git pull`

**Purpose:**
Downloads the latest changes from the remote repository and automatically merges them into your current branch.

**When to use:**
Use `git pull` when you want to update your local repository with the latest changes from GitHub.

**Example:**

```bash
git pull origin main
```

---

## Comparison Table

| Command     | Purpose                                                      | When to Use                                                            |
| ----------- | ------------------------------------------------------------ | ---------------------------------------------------------------------- |
| `git clone` | Creates a local copy of a remote repository.                 | First time downloading a repository.                                   |
| `git fetch` | Retrieves remote changes without merging them.               | When you want to inspect updates before merging.                       |
| `git pull`  | Retrieves and merges remote changes into the current branch. | When you want to update your local repository with the latest changes. |

---

## Summary

* **`git clone`** is used to download a repository for the first time.
* **`git fetch`** retrieves updates without changing your local files.
* **`git pull`** retrieves and merges updates into your current branch.

These commands help developers collaborate efficiently by keeping local repositories synchronized with remote repositories while providing different levels of control over incoming changes.
