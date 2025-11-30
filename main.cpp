#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Max number ng recipe
const int MAX_RECIPES = 50;

// Arrays
string recipeNames[MAX_RECIPES];
string recipeCategories[MAX_RECIPES];
string recipeIngredients[MAX_RECIPES];
string recipeInstructions[MAX_RECIPES];
int recipePrepTime[MAX_RECIPES];
int recipeServings[MAX_RECIPES];

int totalRecipes = 0;  // kung ilang recipe na ang meron

// menu
void showMenu() {
	cout << "\n==============================\n";
	cout << "  RECIPE MANAGEMENT SYSTEM\n";
	cout << "==============================\n";
	cout << "1. Add New Recipe\n";
	cout << "2. View All Recipes\n";
	cout << "3. Search Recipe by Name\n";
	cout << "4. Delete Recipe\n";
	cout << "5. Save Recipes\n";
	cout << "6. Exit\n";
	cout << "==============================\n";
}

// add recipe
void addRecipe() {
	if (totalRecipes >= MAX_RECIPES) {
		cout << "\nSorry! Recipe book is full.\n";
		return;
	}

	cout << "\n--- ADD NEW RECIPE ---\n";

	cout << "Enter recipe name: ";
	getline(cin, recipeNames[totalRecipes]);

	cout << "Enter category (Dessert/Main Course/Appetizer): ";
	getline(cin, recipeCategories[totalRecipes]);

	cout << "Enter ingredients: ";
	getline(cin, recipeIngredients[totalRecipes]);

	cout << "Enter cooking instructions: ";
	getline(cin, recipeInstructions[totalRecipes]);

	totalRecipes++;  // Increase the count

	cout << "\nRecipe added successfully!\n";
}

// view
void viewAllRecipes() {
	cout << "\n--- ALL RECIPES ---\n";

	if (totalRecipes == 0) {
		cout << "No recipes found. Add some recipes first!\n";
		return;
	}

	for (int i = 0; i < totalRecipes; i++) {
		cout << "\nRecipe #" << (i + 1) << "\n";
		cout << "Name: " << recipeNames[i] << "\n";
		cout << "Category: " << recipeCategories[i] << "\n";
		cout << "Ingredients: " << recipeIngredients[i] << "\n";
		cout << "Instructions: " << recipeInstructions[i] << "\n";
		cout << "----------------------------\n";
	}
}

// search
void searchRecipe() {
	cout << "\n--- SEARCH RECIPE ---\n";
	cout << "Enter recipe name to search: ";
	string searchName;
	getline(cin, searchName);

	bool found = false;

	for (int i = 0; i < totalRecipes; i++) {
		if (recipeNames[i] == searchName) {
			cout << "\nRecipe Found!\n";
			cout << "Name: " << recipeNames[i] << "\n";
			cout << "Category: " << recipeCategories[i] << "\n";
			cout << "Ingredients: " << recipeIngredients[i] << "\n";
			cout << "Instructions: " << recipeInstructions[i] << "\n";
			found = true;
			break;  // Stop searching once found
		}
	}

	if (!found) {
		cout << "Recipe not found.\n";
	}
}

// delete
void deleteRecipe() {
	cout << "\n--- DELETE RECIPE ---\n";

	if (totalRecipes == 0) {
		cout << "No recipes to delete.\n";
		return;
	}

	viewAllRecipes();

	cout << "\nEnter recipe number to delete: ";
	int recipeNumber;
	cin >> recipeNumber;
	cin.ignore();

	if (recipeNumber < 1 || recipeNumber > totalRecipes) {
		cout << "Invalid recipe number!\n";
		return;
	}

	int index = recipeNumber - 1; 

	cout << "Are you sure you want to delete '" << recipeNames[index] << "'? (y/n): ";
	char confirm;
	cin >> confirm;
	cin.ignore();

	if (confirm == 'y' || confirm == 'Y') {
		// Shift all recipes after this one up
		for (int i = index; i < totalRecipes - 1; i++) {
			recipeNames[i] = recipeNames[i + 1];
			recipeCategories[i] = recipeCategories[i + 1];
			recipeIngredients[i] = recipeIngredients[i + 1];
			recipeInstructions[i] = recipeInstructions[i + 1];

		}

		totalRecipes--;  // Decrease the count
		cout << "Recipe deleted successfully!\n";
	} else {
		cout << "Deletion cancelled.\n";
	}
}

//save
void saveRecipes() {
	ofstream file("recipes.txt");

	if (!file) {
		cout << "\nError: Could not save recipes!\n";
		return;
	}

	file << totalRecipes << "\n";

	for (int i = 0; i < totalRecipes; i++) {
		file << recipeNames[i] << "\n";
		file << recipeCategories[i] << "\n";
		file << recipeIngredients[i] << "\n";
		file << recipeInstructions[i] << "\n";
	}

	file.close();
	cout << "\nRecipes saved successfully!\n";
}

// Function to load recipes from a file
void loadRecipes() {
	ifstream file("recipes.txt");

	if (!file) {
		return;
	}

	file >> totalRecipes;
	file.ignore();

	for (int i = 0; i < totalRecipes; i++) {
		getline(file, recipeNames[i]);
		getline(file, recipeCategories[i]);
		file.ignore();
		getline(file, recipeIngredients[i]);
		getline(file, recipeInstructions[i]);
	}

	file.close();
}

int main() {
	int choice;

	loadRecipes();

	cout << "Welcome to our Recipe Management System!\n";
	if (totalRecipes > 0) {
		cout << "Loaded " << totalRecipes << " recipes from file.\n";
	}

	// main loop 
	while (true) {
		showMenu();
		cout << "Enter your choice (1-6): ";
		cin >> choice;
		cin.ignore();  // Clear the Enter key

		if (choice == 1) {
			addRecipe();
		} else if (choice == 2) {
			viewAllRecipes();
		} else if (choice == 3) {
			searchRecipe();
		} else if (choice == 4) {
			deleteRecipe();
		} else if (choice == 5) {
			saveRecipes();
		} else if (choice == 6) {
			saveRecipes();
			cout << "\nThank you for using Recipe Management System!\n";
			cout << "Goodbye!\n";
			break;  // exit
		} else {
			cout << "\nInvalid choice! Please enter a number between 1 and 6.\n";
		}

		cout << "\nPress Enter to continue...";
		cin.get();
	}

	return 0;
}