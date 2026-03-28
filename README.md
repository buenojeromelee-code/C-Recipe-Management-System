##PORTABOWL — Recipe Management System

A simple command-line recipe management system written in C++. PORTABOWL lets you store, organize, search, and manage your favorite recipes — all from the terminal.

---

## Features

- **Add Recipes** — Store a recipe's name, category, ingredients, and cooking instructions
- **View All Recipes** — Browse your entire recipe collection at a glance
- **Search by Name** — Quickly find a specific recipe by its name
- **Edit Recipes** — Update any field of an existing recipe, or edit everything at once
- **Delete Recipes** — Remove recipes you no longer need
- **Save & Load** — Recipes are saved to a `recipes.txt` file and automatically loaded on startup

---

## Getting Started

### Prerequisites

- A C++ compiler (e.g. `g++` via GCC or MinGW)

### Build

```bash
g++ portabowl.cpp -o portabowl
```

### Run

```bash
./portabowl
```

On Windows:
```bash
portabowl.exe
```

---

## Usage

When you launch the program, you'll be greeted with the main menu:

```
==============================
PORTABOWL: RECIPE MANAGEMENT SYSTEM
==============================
1. Add New Recipe
2. View All Recipes
3. Search Recipe by Name
4. Edit Recipe
5. Delete Recipe
6. Save Recipes
7. Exit
==============================
```

Enter the number corresponding to the action you want to perform. Recipes are **not saved automatically** — use option `6` before exiting to keep your changes.

### Recipe Fields

| Field        | Description                                      |
|--------------|--------------------------------------------------|
| Name         | The name of the recipe                           |
| Category     | e.g. `Dessert`, `Main Course`, `Appetizer`       |
| Ingredients  | A list of ingredients                            |
| Instructions | Step-by-step cooking instructions                |

---

## Data Storage

Recipes are saved to a plain text file called `recipes.txt` in the same directory as the program. This file is loaded automatically every time you start PORTABOWL.

> ⚠️ The program supports a maximum of **50 recipes**.

---

## Project Structure

```
portabowl/
├── portabowl.cpp   # Main source file
├── recipes.txt     # Auto-generated save file (created on first save)
└── README.md
```

---

## Built With

- **C++** — Standard Library (`iostream`, `string`, `fstream`)
- Array-based storage (no STL containers)

---

## Author

Made with ❤️ as a small C++ project.
