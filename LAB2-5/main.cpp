#include <iostream>
#include "MyVector.cpp"
#include "MySet.cpp"

using namespace std;

void demoStringContainers() {
    cout << "\n=== Демонстрация работы с текстовыми данными (char*) ===\n";
    
    MyVector<char*> v("Hello!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    cout << "Вектор v: " << v << endl;
    
    v.add_element("Привет!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    cout << "Вектор v после добавления: " << v << endl;
    
    MyVector<char*> v1 = v;
    cout << "Вектор v1 (копия v): " << v1 << endl;
    
    for (int i = 0; i < MAX_SIZE; i++)
        v1.delete_element(0);
    cout << "Вектор v1 после удаления: " << v1 << endl;
    
    MySet<char*> s("Yes"), s1, s2;
    s.add_element("Привет!");
    s.add_element("No");
    char str[] = "Hello!";
    s.add_element(str);
    cout << "Множество s: " << s << endl;
    
    s1.add_element("Cat");
    s1.add_element("No");
    s1.add_element("Привет!");
    cout << "Множество s1: " << s1 << endl;
    
    s2 = s1 - s;
    cout << "Разность s1 - s: " << s2 << endl;
    
    s2 = s1 + s;
    cout << "Объединение s1 + s: " << s2 << endl;
    
    s2 = s1 * s;
    cout << "Пересечение s1 * s: " << s2 << endl;
    
    MySet<char*> s3 = s2;
    cout << "Множество s3 (копия s2): " << s3 << endl;
    
    if (s3 == s1)
        cout << "s3 равно s1\n";
    else
        cout << "s3 не равно s1\n";
}

void demoNumericContainers() {
    cout << "\n=== Демонстрация работы с числовыми данными (int) ===\n";
    
    MyVector<int> v(10);
    v.add_element(20);
    v.add_element(30);
    v.add_element(20);
    v.add_element(40);
    cout << "Числовой вектор v: " << v << endl;
    
    v.sort();
    cout << "Отсортированный вектор v: " << v << endl;
    
    MySet<int> s, s1, s2;
    s.add_element(10);
    s.add_element(20);
    s.add_element(30);
    cout << "Числовое множество s: " << s << endl;
    
    s1.add_element(20);
    s1.add_element(40);
    s1.add_element(50);
    cout << "Числовое множество s1: " << s1 << endl;
    
    s2 = s1 - s;
    cout << "Разность s1 - s: " << s2 << endl;
    
    s2 = s1 + s;
    cout << "Объединение s1 + s: " << s2 << endl;
    
    s2 = s1 * s;
    cout << "Пересечение s1 * s: " << s2 << endl;
    
    if (s2 == s1)
        cout << "s2 равно s1\n";
    else
        cout << "s2 не равно s1\n";
}

int main() {
    setlocale(LC_ALL, "Russian");

    demoStringContainers();
    demoNumericContainers();

    return 0;
}