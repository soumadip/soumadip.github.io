//Defining the Employee Structure:
struct Employee {
    char name[50];
    int id;
    float salary;
};


//Adding Employee Records: You will need to dynamically allocate memory to store the employee records.
struct Employee *add_employee(struct Employee *employees, int *count) {
    employees = realloc(employees, (*count + 1) * sizeof(struct Employee));
    printf("Enter name: ");
    scanf("%s", employees[*count].name);
    printf("Enter ID: ");
    scanf("%d", &employees[*count].id);
    printf("Enter salary: ");
    scanf("%f", &employees[*count].salary);
    (*count)++;
    return employees;
}


//Displaying Employee Records: Loop through the array of employee structures and print the details.
void display_employees(struct Employee *employees, int count) {
    for (int i = 0; i < count; i++) {
        printf("Employee %d: Name: %s, ID: %d, Salary: %.2f\n", i+1, employees[i].name, employees[i].id, employees[i].salary);
    }
}


//Saving Employee Records to a File: Use fopen() to open a file and write the employee records using fwrite() for binary file operations or fprintf() for text files.
void save_employees_to_file(struct Employee *employees, int count) {
    FILE *file = fopen("employees.dat", "wb");
    fwrite(employees, sizeof(struct Employee), count, file);
    fclose(file);
}


//Loading Employee Records from a File: Use fread() to read the employee records back into memory.
struct Employee* load_employees_from_file(int *count) {
    FILE *file = fopen("employees.dat", "rb");
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);
    *count = file_size / sizeof(struct Employee);
    struct Employee *employees = malloc(file_size);
    fread(employees, sizeof(struct Employee), *count, file);
    fclose(file);
    return employees;
}




//Defining the Product Structure:
struct Product {
    char name[50];
    int id;
    float price;
};

//Adding Products: Dynamically allocate memory for products using realloc().
struct Product* add_product(struct Product *products, int *count) {
    products = realloc(products, (*count + 1) * sizeof(struct Product));
    printf("Enter product name: ");
    scanf("%s", products[*count].name);
    printf("Enter product ID: ");
    scanf("%d", &products[*count].id);
    printf("Enter product price: ");
    scanf("%f", &products[*count].price);
    (*count)++;
    return products;
}

//Finding the Product with the Highest Price: Loop through the array of products and track the highest price.
struct Product find_highest_price(struct Product *products, int count) {
    struct Product max_product = products[0];
    for (int i = 1; i < count; i++) {
        if (products[i].price > max_product.price) {
            max_product = products[i];
        }
    }
    return max_product;
}

//Saving the Product List to a File: Save the product list to a file using fwrite() for binary files or fprintf() for text files.
void save_products_to_file(struct Product *products, int count) {
    FILE *file = fopen("products.dat", "wb");
    fwrite(products, sizeof(struct Product), count, file);
    fclose(file);
}


//Reading the Product List from a File: Load the products back from the file using fread().
struct Product* load_products_from_file(int *count) {
    FILE *file = fopen("products.dat", "rb");
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);
    *count = file_size / sizeof(struct Product);
    struct Product *products = malloc(file_size);
    fread(products, sizeof(struct Product), *count, file);
    fclose(file);
    return products;
}
