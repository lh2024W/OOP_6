// OOP_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>
using namespace std;

class ElektricKettle {
    char* brand;//бренд
    string model;//модель
    string color;//цвет
    int price;//цена

public:

    ElektricKettle() : ElektricKettle("Philips", "10W", 2000) {}
    //main c-tor
    ElektricKettle(const char* b, string model, int price) {
        brand = new char[strlen(b) + 1];
        strcpy_s(brand, strlen(b) + 1, b);
        SetBrand("Delongi");
        SetModel(model);
        SetColor("White");
        SetPrice(price);
    }

    ~ElektricKettle() { // деструктор
        //cout << "Dest \n";
        delete[] brand;
    }

    ElektricKettle(ElektricKettle& original) // копирование обьекта
    {
        brand = new char[strlen(original.brand) + 1];
        strcpy_s(brand, strlen(original.brand) + 1, original.brand);
        model = original.model;
        color = original.color;
        price = original.price;
    }

    void PrintElektricKettle() const {
        cout << "Brand: " << brand << "\n";
        cout << "Model: " << model << "\n";
        cout << "Color: " << color << "\n";
        cout << "Price: " << price << "\n";
    }

    void SetBrand(const char* b) {
        if (brand == "Tefal" || brand == "Philips" || brand == "Delongi" || brand == "Smeg")
            this->brand = brand;
        else
            cout << "Brand must be \"Tefal\" or \"Philips\" or \"Delongi\" or \"Smeg\"\n";
    }

    void SetModel(string model) {
        if (model != " " || model != "0")
            this->model = model;
        else
            cout << "There is no such model!";
    }

    void SetColor(string color) {
        if (color == "White" || color == "Red" || color == "Black")
            this->color = color;
        else
            cout << "Color must be \"White\" or \"Red\" or \"Black\"";
    }

    void SetPrice(int price) {
        if (price != 0)
            this->price = price;
        else
            cout << "You didn't enter a price!";
    }

    char* GetBrand() const {
        return brand;
    }

    string GetModel() const {
        return model;
    }

    string GetColor() const {
        return color;
    }

    int GetPrice() const {
        return price;
    }

    void PrintPriceColor(int price, string color) const {
        cout << "Price: " << price << "\nColor: " << color << "\n\n";
    }

    void PrintBrandModel(const char* b, string model) const {
        cout << "Brand: " << brand << "\nModel: " << model << "\n\n";
    }

    ElektricKettle operator + (const ElektricKettle& right) {
        ElektricKettle result;
        result.price = this -> price + right.price;
         return result;
    }
};

istream& operator >> (istream& cin, ElektricKettle& k) {
      
    char* brand=new char;//бренд
    string model;//модель
    string color;//цвет
    int price;//цена

    cout << "Enter the characteristics of the electric kettle!\n";
    cout << "Brand: \n";
    cin >> brand;
    k.SetBrand(brand);
    cout << "Model: \n";
    cin >> model;
    k.SetModel(model);
    cout << "Color: \n";
    cin >> color;
    k.SetColor(color);
    cout << "Price: \n";
    cin >> price;
    k.SetPrice(price);
    return cin;
}

ostream& operator << (ostream& cout, const ElektricKettle& k) {
    cout << "Brand: " << k.GetBrand() << "\n";
    cout << "Model: " << k.GetModel() << "\n";
    cout << "Color: " << k.GetColor() << "\n";
    cout << "Price: " << k.GetPrice() << "\n";
    return cout;
}

bool operator < (const ElektricKettle & left, const ElektricKettle & right) {
    if (left.GetPrice() < right.GetPrice()) return true;
    else return false;
}

bool operator > (const ElektricKettle& left, const ElektricKettle& right) {
    if (left.GetPrice() > right.GetPrice()) return true;
    else return false;
}

ElektricKettle operator * (const ElektricKettle& k, int a) {
    ElektricKettle result;
    result.SetPrice(k.GetPrice() * a);
    return result;
}

/*
ElektricKettle operator + (const ElektricKettle& left, const ElektricKettle& right) {
    ElektricKettle result;
    result.SetPrice(left.GetPrice() + right.GetPrice());
    return result;
}
*/

class Book {
    string genre;//жанр
    string author;//автор
    char* name;//название книги
    int year;//год выпуска
    int count_page;//количество страниц

public:

    Book() : Book("Financier", "Theodore Dreiser", 1912, 456) {}

    Book(const char* n, int year, int count_page) : Book() {}
    //main c-tor
    Book(const char* n, string author, int year, int count_page) {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
        SetName(name);
        SetAuthor(author);
        SetGenre("novel");
        SetYear(year);
        SetCountPage(count_page);
    }

    ~Book() { // деструктор
        //cout << "Dest \n";
        delete[] name;
    }

    Book(Book& original) // копирование обьекта
    {
        genre = original.genre;
        author = original.author;
        name = new char[strlen(original.name) + 1];
        strcpy_s(name, strlen(original.name) + 1, original.name);
        year = original.year;
        count_page = original.count_page;
    }

    void PrintBook() const {
        cout << "Author: " << author << "\n";
        cout << "Name: " << name << "\n";
        cout << "Genre: " << genre << "\n";
        cout << "Year: " << year << "\n";
        cout << "Count pages: " << count_page << "\n";
    }

    void SetAuthor(string author) {
        if (author != "Pushkin" || author != "Gogol" || author != "Dostoevsky")
            this->author = author;
        else
            cout << "The author should not be \"Pushkin\" or  \"Gogol\" or \"Dostoevsky\"\n";
    }

    void SetName(const char* n) {
        if (name != "Ruslan and Ludmila" || name != "Dead Souls" || name != "Demons")
            this->name = name;
        else
            cout << "The name book should not be \"Ruslan and Ludmila\" or  \"Dead Souls\" or \"Demons\"\n";
    }

    void SetGenre(string genre) {
        if (genre != "fairy tales" || genre != "fables")
            this->genre = genre;
        else
            cout << "The genre of book should not be \"fairy tales\" or  \"fables\"\n";
    }

    void SetYear(int year) {
        if (year != 0 && year < 2025)
            this->year = year;
        else
            cout << "The year must be from 0 to 2025\n";
    }

    void SetCountPage(int count_page) {
        if (count_page != 0)
            this->count_page = count_page;
        else
            cout << "You did not enter the number of pages \n";
    }

    string GetAuthor() const {
        return author;
    }

    char* GetName() const {
        return name;
    }

    string GetGenre() const {
        return genre;
    }

    int GetYear() const {
        return year;
    }

    int GetCountPage() const {
        return count_page;
    }

    void PrintBook(const char* n, string author, string genre) const {
        cout << "Author: " << author << "\nName: " << name << "\nGenre: " << genre << "\n\n";
    }

    void PrintCountPageYear(const char* n, int count_page, int year) const {
        cout << "Name: " << name << "\nCount page: " << count_page << "\nYear: " << year << "\n\n";
    }

    void Year(int year) const {
        if (year > 2000) {
            cout << "New book!" << year << "\n\n";
        }
        else
            cout << "Old book!" << year << "\n\n";
    }

};

istream& operator >> (istream& cin, Book& b) {

    string genre;//жанр
    string author;//автор
    char* name=new char;//название книги
    int year;//год выпуска
    int count_page;//количество страниц

    cout << "Enter the book!\n";
    cout << "Genre: \n";
    cin >> genre;
    b.SetGenre(genre);
    cout << "Author: \n";
    cin >> author;
    b.SetAuthor(author);
    cout << "Name of the book: \n";
    cin >> name;
    b.SetName(name);
    cout << "Year: \n";
    cin >> year;
    b.SetYear(year);
    cout << "Count page: \n";
    cin >> count_page;
    b.SetCountPage(count_page);
    return cin;
}

ostream& operator << (ostream& cout, const Book& b) {
    cout << "Author: " << b.GetAuthor() << "\n";
    cout << "Name: " << b.GetName() << "\n";
    cout << "Genre: " << b.GetGenre() << "\n";
    cout << "Year: " << b.GetYear() << "\n";
    cout << "Count pages: " << b.GetCountPage() << "\n";
    return cout;
}

bool operator < (const Book& left, const Book& right) {
    if (left.GetCountPage() < right.GetCountPage()) return true;
    else return false;
}

bool operator > (const Book& left, const Book& right) {
    if (left.GetCountPage() > right.GetCountPage()) return true;
    else return false;
}


int main()
{
    ElektricKettle k;
    ElektricKettle k1("Delongi", "10WE", 3600);

    cin >> k >> k1;

    cout << k << "\n" << k1;

    cout << k * 2 << "\n";

    cout << k + k1 << "\n";

    k.GetPrice();
    k1.GetPrice();
    if (k > k1) {
        cout << "\nThe first electric kettle is cheaper \n\n";
    }
    else {
        cout << "\nThe second electric kettle is cheaper \n\n";
    }


    cout << "======================== \n";


    Book b;
    Book b1("Pillars of the Earth", "Ken Follett", 1989, 230);

    cin >> b >> b1;

    cout << b << "\n" << b1;

    b.GetCountPage();
    b1.GetCountPage();

    if (b > b1) {
        cout << "\nThe first book contains more sheets \n\n";
    }
    else {
        cout << "\nThe second book contains more sheets \n\n";
    }


   


    /*
    ElektricKettle k;
    k.PrintElektricKettle();
    cout << "\n\n";

    ElektricKettle k1("Delongi", "10WE", 3600);
    k1.PrintElektricKettle();
    cout << "\n\n";

    ElektricKettle k3 = k; // копирование обьекта
    k3.PrintElektricKettle();
    cout << "\n\n";


    
    Book b;
    b.PrintBook();
    cout << "\n\n";

    Book b1("Three people in the boat, not counting the dog", 1889, 250);
    b1.PrintBook();
    cout << "\n\n";

    Book b2("Pillars of the Earth", "Ken Follett", 1989, 230);
    b2.PrintBook();
    cout << "\n\n";

    Book b3 = b; // копирование обьекта
    b3.PrintBook();
    cout << "\n\n";
    */
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
