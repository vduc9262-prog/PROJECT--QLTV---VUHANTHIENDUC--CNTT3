
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 1000
#define BOOKS_PER_PAGE 10
#define MAX_BORROW 200

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    int bookId;
    char title[50];
    char author[50];
    int publishYear;
    int quantity;
} Book;
Book books[MAX] = {
    {1,  "Toi thay toi tren duong",                  "Nguyen Nhat Anh",        2018, 10},
    {2,  "Dac nhan tam",                             "Dale Carnegie",          1936, 15},
    {3,  "Nha gia kim",                              "Paulo Coelho",           1988, 8},
    {4,  "One Hundred Years of Solitude",            "Gabriel Garcia Marquez", 1967, 5},
    {5,  "Cho toi xin mot ve di tuoi tho",           "Nguyen Nhat Anh",        2012, 12},
    {6,  "The Hobbit",                               "J.R.R. Tolkien",         1937, 9},
    {7,  "Tuoi tre dang gia bao nhieu",              "Rosie Nguyen",           2017, 20},
    {8,  "Cafe cung Tony",                           "Tony Buoi Sang",         2015, 18},
    {9,  "Muon kiep nhan sinh",                      "Nguyen Anh Tuan",        2020, 25},
    {10, "Con duong Hoi giao",                       "Nguyen Xuan Vinh",       2019, 7},
    {11, "Mat biec",                                 "Nguyen Nhat Anh",        1990, 15},
    {12, "Doraemon",                                 "Fujiko F. Fujio",        1974, 30},
    {13, "Harry Potter va Hoi phuong hoang",         "J.K. Rowling",           2003, 10},
    {14, "Hacker's Delight",                         "Henry S. Warren",        2002, 6},
    {15, "Clean Code",                               "Robert C. Martin",       2008, 14},
    {16, "Tuoi tre hoai phi",                        "Rosie Nguyen",           2019, 22},
    {17, "Nguoi trong mot",                          "Do Nhat Nam",            2016, 11},
    {18, "Operating System Concepts",                "Silberschatz",           2018, 8},
    {19, "Toi tu hoc",                               "Nguyen Duy Can",         2010, 20},
    {20, "Con meo day bien troi va khoa hoc",        "Stephane Garnier",       2019, 9},
    {21, "Nghin le mot dem",                         "Nguyen Tuan",            1940, 7},
    {22, "Computer Networks",                        "Andrew Tanenbaum",       2010, 12},
    {23, "Bo gia",                                   "Nguyen Nhat Anh",        2021, 18},
    {24, "Yeu nhung dieu khong hoan hao",            "Haemin Sunim",           2018, 25},
    {25, "Dung chay theo so dong",                   "Damien Webb",            2020, 10},
    {26, "Nghin canh chim bo ca",                    "Harper Lee",             1960, 6},
    {27, "Tam quoc dien nghia",                      "La Quan Trung",          1522, 15},
    {28, "Song nhu ngay mai se chet",                "Robin Sharma",           2018, 13},
    {29, "Atomic Habits",                            "James Clear",            2018, 30},
    {30, "Dung bao gio di an mot minh",              "Keith Ferrazzi",         2005, 11},
    {31, "The Power of Habit",                       "Charles Duhigg",         2012, 14},
    {32, "Sapphire Blue",                            "Kerstin Gier",           2012, 8},
    {33, "Thay do",                                  "Nguyen Nhat Anh",        2018, 17},
    {34, "Tuoi tho du doi",                          "Nguyen Nhat Anh",        2010, 20},
    {35, "The Little Prince",                        "Antoine de Saint-Exupery", 1943, 25},
    {36, "Introduction to Algorithms (CLRS)",       "Thomas H. Cormen",       2022, 10}
};

 Book listBook[MAX]={{1,"To Kill a Mockingbird","Harper Lee",1960,3},
                  {2,"Pride and Prejudice","Jane Austen",1913,5},
                  {3,"The Great Gatsby","F. Scott Fitzgerald",1925,4},
                  {4,"One Hundred Years of Solitude","Gabriel Garcia Marquez",1967,1},
                  {5,"The Catcher in the Rye","J.D. Salinger",1951,7},
                  {6,"The Hobbit","J.R.R. Tolkien",1937,4},
                  {7,"The Alchemist","Paulo Coelho",1988,5},
                  {8,"Crime and Punishment","Fyodor Dostoevsky",1966,2},
                  {9,"The Old Man and the Sea","Ernest Hemingway",1952,1},
                  {10,"War and Peace","Leo Tolstoy",1969,6},
                  {11,"Brave New World","Aldous Huxley",1932,3},
                  {12,"The Lord of the Rings","J.R.R. Tolkien",1954,8},
                  {13,"Jane Eyre","Charlotte Bronte",1947,5},
                  {14,"Wuthering Heights","Emily Bronte",1947,3},
                  {15,"The Brothers Karamazov","Fyodor Dostoevsky",1980,1},
                  {16,"Les Miserables","Victor Hugo",1962,5},
                  {17,"Don Quixote","Miguel de Cervantes",1905,7},
                  {18,"Fahrenheit 451","Ray Bradbury",1953,2},
                  {19,"The Divine Comedy","Dante Alighieri",1999,8},
                  {20,"Anna Karenina","Leo Tolstoy",1977,2},
                  {21,"The Grapes of Wrath","John Steinbeck",1939,5},
                  {22,"The Odyssey","Homer",2000,1},
                  {23,"Moby-Dick","Herman Melville",1951,9},
                  {24,"Hamlet","William Shakespeare",2003,7},
                  {25,"The Iliad","Homer",1970,3},
                  {26,"Great Expectations","Charles Dickens",1961,2},
                  {27,"The Kite Runner","Khaled Hosseini",2003,1},
                  {28,"Life of Pi","Yann Martel",2001,5},
                  {29,"Beloved","Toni Morrison",1987,3},
                  {30,"Catch-22","Joseph Heller",1961,5},
                  {31,"Dracula","Bram Stoker",1997,6},
                  {32,"Frankenstein","Frankenstein",1918,1},
                  {33,"The Sound and the Fury","William Faulkner",1929,8},
                  {34,"Slaughterhouse-Five","Kurt Vonnegut",1969,6},
                  {35,"The Picture of Dorian Gray","Oscar Wilde",1990,2}
    };
    
typedef struct {
    int borrowId;
    int bookId;
    Date borrowDate;
    Date borrowReturn;
    char borrowerName[50];
    int status;
} Borrow;
Borrow borrows[MAX_BORROW] = {
    {1,1,{15,10,2024},{15,11,2025},"VU HAN THIEN DUC",1},
    {2,2,{16,10,2024},{16,12,2025},"VU HAN THIEN DUC",0},
    {3,4,{17,10,2024},{17,11,2025},"VU HAN THIEN DUC",0},
    {4,1,{18,10,2024},{18,12,2025},"VU HAN THIEN DUC",0},
    {5,6,{19,10,2024},{0,0,0},"VU HAN THIEN DUC",1},
    {6,22,{20,10,2024},{20,11,2025},"VU HAN THIEN DUC",0},
    {7,18,{21,10,2024},{21,12,2025},"VU HAN THIEN DUC",0},
    {8,14,{22,10,2024},{22,11,2025},"VU HAN THIEN DUC",0},
    {9,36,{23,10,2024},{0,0,0},"VU HAN THIEN DUC",1},
    {10,6,{24,10,2024},{24,12,2025},"VU HAN THIEN DUC",0},
    {11,22,{25,10,2024},{25,11,2025},"VU HAN THIEN DUC",0},
    {12,18,{26,10,2024},{0,0,0},"VU HAN THIEN DUC",1},
    {13,14,{27,10,2024},{27,12,2025},"VU HAN THIEN DUC",0},
    {14,36,{28,10,2024},{28,11,2025},"VU HAN THIEN DUC",0},
    {15,14,{29,10,2024},{29,12,2025},"VU HAN THIEN DUC",0},
    {16,1,{30,10,2024},{30,11,2025},"VU HAN THIEN DUC",0},
    {17,2,{1,11,2024},{0,0,0},"VU HAN THIEN DUC",1},
    {18,4,{2,11,2024},{0,0,0},"VU HAN THIEN DUC",1},
    {19,1,{3,11,2024},{3,1,2026},"VU HAN THIEN DUC",0},
    {20,6,{4,11,2024},{0,0,0},"VU HAN THIEN DUC",1},
    {21,22,{5,11,2024},{5,12,2025},"VU HAN THIEN DUC",0},
    {22,18,{6,11,2024},{6,1,2026},"VU HAN THIEN DUC",0},
    {23,14,{7,11,2024},{7,12,2025},"VU HAN THIEN DUC",0},
    {24,36,{9,11,2024},{8,1,2026},"VU HAN THIEN DUC",0},
    {25,6,{9,11,2024},{0,0,0},"VU HAN THIEN DUC",1},
    {26,22,{10,11,2024},{10,12,2025},"VU HAN THIEN DUC",0},
    {27,18,{11,11,2024},{0,0,0},"VU HAN THIEN DUC",1},
    {28,14,{12,11,2024},{12,1,2026},"VU HAN THIEN DUC",0},
    {29,36,{13,11,2024},{0,0,0},"VU HAN THIEN DUC",1},
    {30,14,{14,11,2024},{14,2,2026},"VU HAN THIEN DUC",0}

};

Book books[MAX];
Borrow borrows[MAX_BORROW];

int bookCount = 36;
int bookIdCounter = 1;
int borrowCount = 30;
int borrowIdCounter = 31;
int page = 1;

void addBook() {
    if (bookCount >= MAX) {
        printf("Thu vien da day!\n");
        return;
    }

    Book b;
    b.bookId = bookIdCounter++;
    fflush(stdin);

    while (1) {
        printf("Nhap tieu de sach: ");
        fgets(b.title, 50, stdin);
        b.title[strcspn(b.title, "\n")] = '\0';

        if (strlen(b.title) == 0) {
            printf("Loi: Khong duoc de trong!\n");
            continue;
        }

        int trung = 0;
        for (int i = 0; i < bookCount; i++) {
            if (strcmp(books[i].title, b.title) == 0) {
                trung = 1;
                break;
            }
        }
        if (trung) {
            printf("Loi: Tieu de da ton tai!\n");
        } else {
            break;
        }
    }

    while (1) {
        printf("Nhap ten tac gia: ");
        fgets(b.author, 50, stdin);
        b.author[strcspn(b.author, "\n")] = '\0';

        if (strlen(b.author) > 0) {
            break;
        }
        printf("Loi: Khong duoc de trong!\n");
    }

    while (1) {
        char input[20];
        int year = 0;
        int valid = 1;

        printf("Nhap nam xuat ban (1900-2025): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            printf("Loi: Khong duoc de trong! Vui long nhap lai.\n");
            continue;
        }

        for (int i = 0; input[i]; i++) {
            if (input[i] < '0' || input[i] > '9') {
                valid = 0;
                break;
            }
        }
        if (!valid) {
            printf("Loi: Vui long nhap so nguyen! Nhap lai.\n");
            continue;
        }

        for (int i = 0; input[i]; i++) {
            year = year * 10 + (input[i] - '0');
        }

        if (year >= 1900 && year <= 2025) {
            b.publishYear = year;
            break;
        } else {
            printf("Loi: Nam phai tu 1900 den 2025! Nhap lai.\n");
        }
    }

    while (1) {
        char input[20];
        int qty = 0;
        int valid = 1;

        printf("Nhap so luong (>0): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            printf("Loi: Khong duoc de trong! Nhap lai.\n");
            continue;
        }

        for (int i = 0; input[i]; i++) {
            if (input[i] < '0' || input[i] > '9') {
                valid = 0;
                break;
            }
        }
        if (!valid) {
            printf("Loi: So luong phai la so nguyen! Nhap lai.\n");
            continue;
        }

        for (int i = 0; input[i]; i++) {
            qty = qty * 10 + (input[i] - '0');
        }

        if (qty > 0) {
            b.quantity = qty;
            break;
        } else {
            printf("Loi: So luong phai lon hon 0! Nhap lai.\n");
        }
    }

    books[bookCount++] = b;

    printf("\n");
    if (bookCount == 1) {
        printf("=== DANH SACH SACH TRONG THU VIEN ===\n");
    } else {
        printf("=== CAP NHAT DANH SACH SACH ===\n");
    }

    printf("+------+--------------------------------+--------------------------------+-------+-------+\n");
    printf("| ID   | TIEU DE                        | TAC GIA                        | NAMXB | SL    |\n");
    printf("+------+--------------------------------+--------------------------------+-------+-------+\n");

    for (int i = 0; i < bookCount; i++) {
        printf("| %4d | %-30s | %-30s | %5d | %5d |\n",
               books[i].bookId,
               books[i].title,
               books[i].author,
               books[i].publishYear,
               books[i].quantity);
    }

    printf("+------+--------------------------------+--------------------------------+-------+-------+\n");
    printf("\nTHEM SACH THANH CONG!\n");
    fflush(stdin);
    

}

void updateBook() {
    if (bookCount == 0) {
        printf("Khong co sach nao trong thu vien!\n");
        fflush(stdin);
        char temp[10];
        fgets(temp, sizeof(temp), stdin);
        return;
    }

    int id;
    int found = 0;
    int index = -1;

    while (1) {
        char input[20];
        int valid = 1;

        printf("Nhap ma sach can cap nhat: ");
        fflush(stdin);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            printf("Loi: Khong duoc de trong! Nhap lai.\n");
            continue;
        }

        for (int j = 0; input[j] != '\0'; j++) {
            if (input[j] < '0' || input[j] > '9') {
                valid = 0;
                break;
            }
        }
        if (!valid) {
            printf("Loi: Chi duoc nhap so nguyen! Nhap lai.\n");
            continue;
        }

        id = atoi(input);

        if (id <= 0) {
            printf("Loi: Ma sach phai la so duong! Nhap lai.\n");
            continue;
        }

        break;
    }

    for (int i = 0; i < bookCount; i++) {
        if (books[i].bookId == id) {
            found = 1;
            index = i;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay ma sach %d!\n", id);
        printf("Nhan Enter de tiep tuc...");
        fflush(stdin);
        char temp[10];
        fgets(temp, sizeof(temp), stdin);
        return;
    }

    printf("\n=== THONG TIN SACH CAN CAP NHAT (ID: %d) ===\n", id);
    printf("+------+--------------------------------+--------------------------------+-------+-------+\n");
    printf("| ID   | TIEU DE                        | TAC GIA                        | NAMXB | SL    |\n");
    printf("+------+--------------------------------+--------------------------------+-------+-------+\n");
    printf("| %4d | %-30s | %-30s | %5d | %5d |\n",
           books[index].bookId,
           books[index].title,
           books[index].author,
           books[index].publishYear,
           books[index].quantity);
    printf("+------+--------------------------------+--------------------------------+-------+-------+\n\n");

    while (1) {
        printf("Tieu de moi (hien tai: %s): ", books[index].title);
        fflush(stdin);
        fgets(books[index].title, 50, stdin);
        books[index].title[strcspn(books[index].title, "\n")] = '\0';

        if (strlen(books[index].title) == 0) {
            printf("Khong duoc de trong!\n");
            continue;
        }

        int trung = 0;
        for (int j = 0; j < bookCount; j++) {
            if (j != index && strcmp(books[j].title, books[index].title) == 0) {
                trung = 1;
                break;
            }
        }
        if (trung) {
            printf("Loi: Tieu de da ton tai o sach khac!\n");
        } else {
            break;
        }
    }

    while (1) {
        printf("Tac gia moi (hien tai: %s): ", books[index].author);
        fflush(stdin);
        fgets(books[index].author, 50, stdin);
        books[index].author[strcspn(books[index].author, "\n")] = '\0';
        if (strlen(books[index].author) > 0) break;
        printf("Khong duoc de trong!\n");
    }

    while (1) {
        char input[20];
        int year;
        printf("Nam XB moi (hien tai: %d): ", books[index].publishYear);
        fflush(stdin);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            printf("Loi: Khong duoc de trong!\n");
            continue;
        }
        year = atoi(input);
        if (year > 1900 && year <= 2025) {
            books[index].publishYear = year;
            break;
        }
        printf("Loi: Nam phai tu 1901 den 2025!\n");
    }

    while (1) {
        char input[20];
        int qty;
        printf("So luong moi (hien tai: %d): ", books[index].quantity);
        fflush(stdin);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            printf("Loi: Khong duoc de trong!\n");
            continue;
        }
        qty = atoi(input);
        if (qty > 0) {
            books[index].quantity = qty;
            break;
        }
        printf("Loi: So luong phai lon hon 0!\n");
    }

    printf("\nCAP NHAT THANH CONG!\n");
    printf("Nhan Enter de tiep tuc...");
    fflush(stdin);
    char temp[10];
    fgets(temp, sizeof(temp), stdin);
}

void displayBooksWithPaging() {

        if (bookCount == 0) {
            printf("Khong co sach nao trong thu vien!\n");
            return;
        }
        int noBack=1;
        int choicePage;
        int totalPages = bookCount /BOOKS_PER_PAGE + (bookCount%BOOKS_PER_PAGE==0?0:1);
        while (noBack) {
            printf("Tong so trang %d, trang danh sach thu %d\n",totalPages,page);
            for(int i=1;i<=106;i++){
                printf("-");
            }
            printf("\n|%-15s|%-30s|%-15s|%-20s|%-20s|\n","Ma so sach","Tieu de sach","Nam phat hanh","tac gia","So luong");
            for(int i=1;i<=106;i++){
                printf("-");
            }
            for(int i= (page-1)*BOOKS_PER_PAGE;i<page*BOOKS_PER_PAGE;i++){

                if(i<bookCount){
                    printf("\n|%-15d|%-30s|%-15d|%-20s|%-20d|\n",listBook[i].bookId,listBook[i].title,listBook[i].publishYear,listBook[i].author,listBook[i].quantity);
                    for(int i=1;i<=106;i++){
                        printf("-");
                    }
                }
            }
            int continueDisplay = 1;
            while(continueDisplay) {
                printf("\nNhap 1 de quay lai trang truoc\n");
                printf("nhap 2 de thoat\n");
                printf("nhap 3 de sang trang tiep theo\n");
                printf("nhap lua chon: ");
                scanf("%d",&choicePage);
                switch(choicePage) {
                    case 1:
                        if (page==1) {
                            break;
                        }else{
                            page--;
                        }
                        continueDisplay = 0;
                        break;
                    case 2:
                        noBack=0;
                        continueDisplay = 0;
                        break;
                    case 3:
                        if (page==totalPages) {
                            break;
                        }else {
                            page++;
                        }
                        continueDisplay = 0;
                        break;
                    default:
                        printf("Loi! Moi ban nhap tu 1-3!!");
                        printf("\n");
                }
            }
        }

    }

int isBookBorrowed(int bookId) {
    return 0;
}

void deleteBook() {
    if (bookCount == 0) {
        printf("Khong co sach nao de xoa!\n");
        return;
    }

    int id;
    int found;

    while (1) {
        found = 0;

   int id = 0;
while (1) {
    char input[20];
    int valid = 1;

    printf("Nhap ma sach can xoa: ");
    fflush(stdin);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strlen(input) == 0) {
        printf("LOI! Khong duoc de trong. Nhap lai!\n");
        continue;
    }

    for (int j = 0; input[j] != '\0'; j++) {
        if (input[j] < '0' || input[j] > '9') {
            valid = 0;
            break;
        }
    }

    if (!valid) {
        printf("LOI! Ban phai nhap so nguyen. Nhap lai!\n");
        continue;
    }

    id = 0;
    for (int j = 0; input[j] != '\0'; j++) {
        id = id * 10 + (input[j] - '0');
    }

    break;
}
        for (int i = 0; i < bookCount; i++) {
            if (books[i].bookId == id) {
                found = 1;

                if (isBookBorrowed(id)) {
                    printf("KHONG THE XOA! Sach co ma %d dang duoc muon chua tra.\n\n", id);
                    break;
                }

                printf("Da xoa thanh cong sach:\n");
    printf("+------+--------------------------------+--------------------------------+-------+-------+\n");
    printf("|  ID  |          TIEU DE               |           TAC GIA              | NAMXB |  SL   |\n");
    printf("+------+--------------------------------+--------------------------------+-------+-------+\n");

    for (int i = 0; i < bookCount; i++) {
        printf("| %4d | %-30s | %-30s | %5d | %5d |\n",
               books[i].bookId,
               books[i].title,
               books[i].author,
               books[i].publishYear,
               books[i].quantity);
    }

                printf("XOA SACH THANH CONG!\n");
                return;
            }
        }
        if (!found) {
            printf("KHONG TIM THAY sach co ma %d! Vui long nhap lai.\n\n", id);
        }
    }
}

void searchBook(){
	 if (bookCount == 0 ){
	 	printf ("Khong co sach nao nhu vay ");
		 return;
	 }
    char keyword[50];
    int found = 0;

    while (1) {
        printf("Nhap ten sach can tim : ");
        fflush(stdin);
        fgets(keyword, 50, stdin);
        keyword[strcspn(keyword, "\n")] = '\0';

        if (strlen(keyword) == 0) {
            printf("LOI! Ten sach khong duoc de trong. Nhap lai!\n\n");
            continue;
        }
        break;
    }

    system("cls");
    printf("================ KET QUA TIM KIEM: \"%s\" ================\n\n", keyword);
    printf("%-6s %-35s %-20s %-10s %s\n", "ID", "Tieu de", "Tac gia", "Nam XB", "SL");
    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < bookCount; i++) {
        char titleLower[50];
        char keyLower[50];
        strcpy(titleLower, books[i].title);
        strcpy(keyLower, keyword);

        for (int j = 0; titleLower[j]; j++) titleLower[j] = tolower(titleLower[j]);
        for (int j = 0; keyLower[j]; j++)   keyLower[j]   = tolower(keyLower[j]);

        if (strstr(titleLower, keyLower) != NULL) {
            printf("%-6d %-35s %-20s %-10d %d\n",
                   books[i].bookId,
                   books[i].title,
                   books[i].author,
                   books[i].publishYear,
                   books[i].quantity);
            found = 1;
        }
    }

    if (!found) {
        printf("     Khong tim thay sach nao chua \"%s\" !\n", keyword);
    }

    printf("Nhan Enter de quay lai menu...");
    fflush(stdin);

}

void createBorrow() {
    if (bookCount == 0) {
        printf("Khong co sach nao de muon!\n");
        return;
    }
    if (borrowCount >= MAX_BORROW) {
        printf("Danh sach phieu muon da day!\n");
        return;
    }

    Borrow b;
    b.borrowId = borrowIdCounter++;

   while (1) {
    char input[20];
    int bookIdInput = 0;
    int valid = 1;
    int found = 0;
    int bookIndex = -1;

    printf("Nhap ma sach can muon: ");
    fflush(stdin);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strlen(input) == 0) {
        printf("LOI! Khong duoc de trong. Nhap lai!\n");
        continue;
    }

    for (int j = 0; input[j] != '\0'; j++) {
        if (input[j] < '0' || input[j] > '9') {
            valid = 0;
            break;
        }
    }
    if (!valid) {
        printf("LOI! Phai nhap so nguyen. Nhap lai!\n");
        continue;
    }

    bookIdInput = 0;
    for (int j = 0; input[j] != '\0'; j++) {
        bookIdInput = bookIdInput * 10 + (input[j] - '0');
    }

    found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].bookId == bookIdInput) {
            bookIndex = i;
            if (books[i].quantity <= 0) {
                printf("LOI! Sach \"%s\" da het!\n", books[i].title);
                found = 0;
                break;
            }

            books[i].quantity--;
            b.bookId = bookIdInput;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Muon sach thanh cong! Con lai: %d cuon.\n", books[bookIndex].quantity);
        break;
    }
    else if (bookIndex == -1) {

        printf("LOI! Khong tim thay ma sach %d. Nhap lai!\n", bookIdInput);
    }

}
    while (1) {
    char line[100];
    int day, month, year;

    printf("Nhap ngay muon (dd mm yyyy): ");
    fflush(stdin);
    if (!fgets(line, sizeof(line), stdin)) continue;
    line[strcspn(line, "\n")] = '\0';

    if (strlen(line) == 0) {
        printf("LOI! Khong duoc de trong. Nhap lai!\n");
        continue;
    }

    if (sscanf(line, "%d %d %d", &day, &month, &year) != 3) {
        printf("LOI! Sai dinh dang. Vui long nhap: dd mm yyyy (vi du: 15 11 2025)\n");
        continue;
    }

    if (day < 1 || day > 31) {
        printf("LOI! Ngay phai tu 1 den 31!\n");
        continue;
    }
    if (month < 1 || month > 12) {
        printf("LOI! Thang phai tu 1 den 12!\n");
        continue;
    }
    if (year < 2000) {
        printf("LOI! Nam muon phai tu 2000 tro di!\n");
        continue;
    }

    b.borrowDate.day   = day;
    b.borrowDate.month = month;
    b.borrowDate.year  = year;

    printf("Da nhan ngay muon: %02d/%02d/%d\n", day, month, year);
    break;
}

    while (1) {
    char line[100];
    int day, month, year;
    int valid = 1;

    printf("Nhap ngay tra du kien (dd mm yyyy): ");
    fflush(stdin);
    if (!fgets(line, sizeof(line), stdin)) continue;
    line[strcspn(line, "\n")] = '\0';

    if (strlen(line) == 0) {
        printf("LOI! Khong duoc de trong. Nhap lai!\n");
        continue;
    }

    if (sscanf(line, "%d %d %d", &day, &month, &year) != 3) {
        printf("LOI! Sai dinh dang. Vui long nhap: dd mm yyyy (vi du: 25 12 2025)\n");
        continue;
    }

    if (day < 1 || day > 31) {
        printf("LOI! Ngay phai tu 1 den 31!\n");
        continue;
    }
    if (month < 1 || month > 12) {
        printf("LOI! Thang phai tu 1 den 12!\n");
        continue;
    }
    if (year < b.borrowDate.year) {
        printf("LOI! Nam tra khong duoc som hon nam muon (%d)!\n", b.borrowDate.year);
        continue;
    }
    if (year == b.borrowDate.year && month < b.borrowDate.month) {
        printf("LOI! Thang tra khong duoc som hon thang muon!\n");
        continue;
    }
    if (year == b.borrowDate.year && month == b.borrowDate.month && day <= b.borrowDate.day) {
        printf("LOI! Ngay tra phai SAU ngay muon (%02d/%02d/%d)!\n",
               b.borrowDate.day, b.borrowDate.month, b.borrowDate.year);
        continue;
    }

    b.borrowReturn.day = day;
    b.borrowReturn.month = month;
    b.borrowReturn.year = year;

    printf("Da nhan ngay tra du kien: %02d/%02d/%d\n", day, month, year);
    break;
}

    while (1) {
        printf("Nhap ten nguoi muon: ");
        fflush(stdin);
        fgets(b.borrowerName, 50, stdin);
        b.borrowerName[strcspn(b.borrowerName, "\n")] = '\0';
        if (strlen(b.borrowerName) > 0) 
		break;
        printf("LOI! Khong duoc de trong. Nhap lai!\n");
    }

    b.status = 1;

    borrows[borrowCount++] = b;

    printf("\n=== TAO PHIEU MUON THANH CONG! ===\n");
    printf("Ma phieu   : %d\n", b.borrowId);
    printf("Ma sach    : %d\n", b.bookId);
    printf("Ngay muon  : %02d/%02d/%d\n", b.borrowDate.day, b.borrowDate.month, b.borrowDate.year);
    printf("Ngay tra   : %02d/%02d/%d\n", b.borrowReturn.day, b.borrowReturn.month, b.borrowReturn.year);
    printf("Nguoi muon : %s\n", b.borrowerName);
    printf("=====================================\n");
}

void returnBook() {
    if (borrowCount == 0) {
        printf("Khong co phieu muon nao!\n");
        return;
    }

    char line[100];
    int id, i, found = 0;

    while (1) {
        printf("Nhap ID phieu muon can tra: ");
        fgets(line, sizeof(line), stdin);
        if (line[0] == '\n' || line[0] == '\0') {
            printf("Loi: Khong duoc de trong! Nhap lai.\n");
            continue;
        }
        id = 0;
        int k = 0;
        while (line[k] >= '0' && line[k] <= '9') {
            id = id * 10 + (line[k] - '0');
            k++;
        }
        if (k > 0 && (line[k] == '\n' || line[k] == '\0')) 
		break;
        printf("Loi: Phai nhap so! Nhap lai.\n");
    }

    for (i = 0; i < borrowCount; i++) {
        if (borrows[i].borrowId == id) {
            if (borrows[i].status == 0) {
                printf("Phieu %d da duoc tra truoc do!\n", id);
                return;
            }
            found = 1; break;
        }
    }
    if (!found) {
        printf("Khong tim thay phieu muon ID %d!\n", id);
        return;
    }

    int d, m, y;
    while (1) {
        printf("Nhap ngay tra (dd mm yyyy): ");
        fgets(line, sizeof(line), stdin);
        if (line[0] == '\n') {
            printf("Loi: Khong duoc de trong! Nhap lai.\n");
            continue;
        }

        int nums[3] = {0,0,0}, idx = 0, num = 0;
        int p = 0, valid = 1;
        while (line[p] && idx < 3) {
            if (line[p] >= '0' && line[p] <= '9') {
                num = num * 10 + (line[p] - '0');
            } else if (num > 0) {
                nums[idx++] = num; num = 0;
            }
            p++;
        }
        if (num > 0) nums[idx++] = num;

        if (idx != 3 || (line[p-1] != '\n' && line[p-1] != '\0')) valid = 0;
        if (!valid) {
            printf("Loi: Nhap sai dinh dang! Nhap lai.\n");
            continue;
        }

        d = nums[0]; m = nums[1]; y = nums[2];

        if (d < 1 || d > 31 || m < 1 || m > 12 || y < 2000) {
            printf("Loi: Ngay thang nam khong hop le!\n");
            continue;
        }
        if (y > borrows[i].borrowDate.year ||
            (y == borrows[i].borrowDate.year && m > borrows[i].borrowDate.month) ||
            (y == borrows[i].borrowDate.year && m == borrows[i].borrowDate.month && d > borrows[i].borrowDate.day))
            break;

        printf("Loi: Ngay tra phai sau ngay muon!\n");
    }

    borrows[i].borrowReturn.day = d;
    borrows[i].borrowReturn.month = m;
    borrows[i].borrowReturn.year = y;
    borrows[i].status = 0;

    for (int j = 0; j < bookCount; j++) {
        if (books[j].bookId == borrows[i].bookId) {
            books[j].quantity++;
            break;
        }
    }

    printf("\n");
    printf("===============================\n");
    printf(" TRA SACH THANH CONG! \n");
    printf("===============================\n");
    printf("ID phieu muon : %d\n", borrows[i].borrowId);
    printf("Ma sach : %d\n", borrows[i].bookId);
    printf("Ngay tra : %02d/%02d/%d\n", d, m, y);
    printf("So luong sach da tang +1\n");
    printf("===============================\n");
}

void displayBorrowList() {
    if (borrowCount == 0) {
        system("cls");
        printf("\n====================================\n");
        printf("   DANH SACH PHIEU MUON TRONG!\n");
        printf("====================================\n\n");
        printf("Nhan Enter de quay lai menu...");
        char temp[10];
        fgets(temp, sizeof(temp), stdin);
        return;
    }

    int page = 1;
    const int itemsPerPage = 10;

    while (1) {
        system("cls");
        int totalPages = (borrowCount + itemsPerPage - 1) / itemsPerPage;
        int start = (page - 1) * itemsPerPage;
        int end = (start + itemsPerPage < borrowCount) ? start + itemsPerPage : borrowCount;

        printf("============================== DANH SACH PHIEU MUON (Trang %d/%d) ==============================\n\n", page, totalPages);
        printf("+--------+--------+--------------------------------+-------------------+--------------+--------------+------------+\n");
        printf("| ID     | Ma sach| Tua de sach                    | Nguoi muon        | Ngay muon    | Ngay tra     | Trang thai |\n");
        printf("+--------+--------+--------------------------------+-------------------+--------------+--------------+------------+\n");

        for (int i = start; i < end; i++) {
            char bookTitle[50] = "Khong tim thay";
            int j;
            for (j = 0; j < bookCount; j++) {
                if (books[j].bookId == borrows[i].bookId) {
                    strcpy(bookTitle, books[j].title);
                    break;
                }
            }
            if (strlen(bookTitle) > 30) {
                bookTitle[27] = '.'; bookTitle[28] = '.'; bookTitle[29] = '.'; bookTitle[30] = '\0';
            }

            char returnStr[15] = "           ";
            char statusStr[15] = "Dang muon";

            if (borrows[i].status == 0) {
                sprintf(returnStr, "%02d/%02d/%d",
                        borrows[i].borrowReturn.day,
                        borrows[i].borrowReturn.month,
                        borrows[i].borrowReturn.year);
                strcpy(statusStr, "Da tra");
            }

            printf("| %-6d | %-6d | %-30s | %-17s | %02d/%02d/%-5d | %-12s | %-10s |\n",
                   borrows[i].borrowId,
                   borrows[i].bookId,
                   bookTitle,
                   borrows[i].borrowerName,
                   borrows[i].borrowDate.day,
                   borrows[i].borrowDate.month,
                   borrows[i].borrowDate.year,
                   returnStr,
                   statusStr);
        }

        printf("+--------+--------+--------------------------------+-------------------+--------------+--------------+------------+\n");
        printf("  Tong: %-3d phieu                                                       Trang %d/%d\n\n", borrowCount, page, totalPages);
        printf("1. Trang truoc    2. Quay lai menu    3. Trang tiep\n");

        int choice = 0;
        char input[10];
        while (1) {
            printf("Chon (1-3): ");
            fflush(stdin);
            if (fgets(input, sizeof(input), stdin) == NULL) continue;
            input[strcspn(input, "\n")] = '\0';

            if (strlen(input) == 0) {
                printf("Loi: Khong duoc de trong! Nhap lai.\n");
                continue;
            }

            int valid = 1;
            for (int k = 0; input[k] != '\0'; k++) {
                if (input[k] < '0' || input[k] > '9') {
                    valid = 0;
                    break;
                }
            }
            if (!valid) {
                printf("Loi: Chi duoc nhap so! Nhap lai.\n");
                continue;
            }

            choice = 0;
            for (int k = 0; input[k] != '\0'; k++) {
                choice = choice * 10 + (input[k] - '0');
            }

            if (choice >= 1 && choice <= 3) {
                break;
            }
            printf("Loi: Chi nhap 1, 2 hoac 3! Nhap lai.\n");
        }

        if (choice == 2) {
            return;
        }
        else if (choice == 1) {
            if (page > 1) {
                page--;
            } else {
                printf("\nBan dang o trang dau tien!\n");
                printf("Nhan Enter de tiep tuc...");
                char temp[10];
                fgets(temp, sizeof(temp), stdin);
            }
        }
        else if (choice == 3) {
            if (page < totalPages) {
                page++;
            } else {
                printf("\nBan dang o trang cuoi cung!\n");
                printf("Nhan Enter de tiep tuc...");
                char temp[10];
                fgets(temp, sizeof(temp), stdin);
            }
        }
    }
}

int main() {
char input[50];
    int choice;
    do {
        system("cls");
        printf("=============== QUAN LY THU VIEN ===============\n");
        printf("|1. Them moi sach                              |\n");
        printf("|2. Cap nhat thong tin sach                    |\n");
        printf("|3. Hien thi danh sach sach                    |\n");
        printf("|4. Xoa sach                                   |\n");
        printf("|5. Tim kiem sach                              |\n");
        printf("|6. Tao phieu muon sach                        |\n");
        printf("|7. Tra sach                                   |\n");
        printf("|8. Hien thi phieu muon                        |\n");
        printf("|9. Thoat                                      |\n");
        printf("================================================\n");
        
        printf("\nNhap lua chon (1-9): ");

        if (!fgets(input, sizeof(input), stdin)) {
            continue;
        }

        choice = 0;
        int valid = 1;
        int i = 0;

        while (input[i] == ' ' || input[i] == '\t') i++;

        if (input[i] == '\n' || input[i] == '\0') {
            valid = 0;
        }

        while (input[i] != '\n' && input[i] != '\0') {
            if (input[i] < '0' || input[i] > '9') {
                valid = 0;
                break;
            }
            choice = choice * 10 + (input[i] - '0');
            i++;
        }

       if (choice >= 10) {
            printf("\nkhong co chuc nang !\n");
        }

        if (!valid ) {
            printf("\nLOI! khong de trong va phai nhap so  .\n");
            getchar();
            continue;
        }

        if (choice == 9) {
            printf("\nCam on ban da su dung chuong trinh!\n");
            break;
        }
        switch (choice) {
            case 1:
			      addBook();
			      getchar();
			      break;
            case 2:
			      updateBook();
			      getchar();
			      break;
			case 3:
			      displayBooksWithPaging();
			      getchar();
				  break;
		    case 4:
		    	  deleteBook();
		    	  getchar();
			      break;
		    case 5:
		    	  searchBook();
		    	  getchar();
			      break;
		    case 6:
		    	 createBorrow();
		    	 getchar();
			      break;
			case 7:
                 returnBook();
                 getchar();
			     break;
			case 8:
				 displayBorrowList();
				 getchar();
			     break;
            case 9:

			    printf("Cam on ban da su dung chuong trinh!\n");

            default:
			        printf("Chua hoan thien!\n");
        }
        printf("\nNhan Enter de tiep tuc...");
        fflush(stdin);
        getchar();
    } while (1);
}

 
