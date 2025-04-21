#include <iostream>
#include <algorithm> // Для std::sort
#include <cstring>   // Для strcmp в специализации char*

// Шаблонный класс динамического массива
template <typename T>
class MyVector {
protected:
    size_t max_size; // Максимальный размер выделенной памяти
    size_t size;     // Текущее количество элементов
    T* pdata;        // Указатель на массив данных

    // Метод изменения размера массива
    void resize(size_t new_max_size) {
        T* new_data = new T[new_max_size]; // Выделяем новую память
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = pdata[i]; // Копируем элементы
        }
        delete[] pdata;    // Освобождаем старую память
        pdata = new_data;   // Обновляем указатель
        max_size = new_max_size; // Обновляем размер
    }

public:
    // Конструктор с параметром по умолчанию
    MyVector(size_t initial_size = 1) : max_size(initial_size), size(0), pdata(new T[initial_size]) {}

    // Конструктор копирования
    MyVector(const MyVector& other) : max_size(other.max_size), size(other.size), pdata(new T[other.max_size]) {
        for (size_t i = 0; i < size; ++i) {
            pdata[i] = other.pdata[i]; // Копируем элементы
        }
    }

    // Деструктор
    ~MyVector() {
        delete[] pdata; // Освобождаем память
    }

    // Оператор присваивания
    MyVector& operator=(const MyVector& other) {
        if (this != &other) { // Проверка на самоприсваивание
            delete[] pdata; // Освобождаем старую память
            max_size = other.max_size;
            size = other.size;
            pdata = new T[max_size]; // Выделяем новую память
            for (size_t i = 0; i < size; ++i) {
                pdata[i] = other.pdata[i]; // Копируем элементы
            }
        }
        return *this;
    }

    // Добавление элемента в конец
    void add_element(const T& element) {
        if (size >= max_size) {
            resize(max_size * 2); // Увеличиваем размер при необходимости
        }
        pdata[size++] = element; // Добавляем элемент
    }

    // Удаление элемента по индексу
    void delete_element(size_t index) {
        if (index >= size) return; // Проверка границ
        
        // Сдвигаем элементы влево
        for (size_t i = index; i < size - 1; ++i) {
            pdata[i] = pdata[i + 1];
        }
        size--; // Уменьшаем счетчик
        
        // Уменьшаем размер если много свободного места
        if (size < max_size / 4 && max_size > 1) {
            resize(std::max(max_size / 2, static_cast<size_t>(1)));
        }
    }

    // Поиск элемента (линейный поиск)
    int find(const T& element) const {
        for (size_t i = 0; i < size; ++i) {
            if (pdata[i] == element) {
                return static_cast<int>(i); // Возвращаем индекс
            }
        }
        return -1; // Элемент не найден
    }

    // Оператор доступа по индексу
    T& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return pdata[index];
    }

    // Константный оператор доступа по индексу
    const T& operator[](size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of range");
        return pdata[index];
    }

    // Сортировка элементов
    void sort() {
        std::sort(pdata, pdata + size); // Используем стандартную сортировку
    }

    // Получение текущего размера
    size_t get_size() const { return size; }
};

// Специализация для типа char*
template <>
class MyVector<char*> {
protected:
    size_t max_size;
    size_t size;
    char** pdata; // Указатель на массив указателей на char

    void resize(size_t new_max_size) {
        char** new_data = new char*[new_max_size];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = pdata[i]; // Копируем указатели
        }
        delete[] pdata;
        pdata = new_data;
        max_size = new_max_size;
    }

public:
    MyVector(size_t initial_size = 1) : max_size(initial_size), size(0), pdata(new char*[initial_size]) {}

    ~MyVector() {
        for (size_t i = 0; i < size; ++i) {
            delete[] pdata[i]; // Освобождаем каждую строку
        }
        delete[] pdata; // Освобождаем массив указателей
    }

    void add_element(const char* element) {
        if (size >= max_size) {
            resize(max_size * 2);
        }
        pdata[size] = new char[strlen(element) + 1]; // Выделяем память под строку
        strcpy(pdata[size], element); // Копируем строку
        size++;
    }

    // Остальные методы аналогичны, но работают с char*
};

// Шаблонный класс множества
template <typename T>
class MySet : public MyVector<T> {
private:
    using MyVector<T>::pdata;
    using MyVector<T>::size;
    using MyVector<T>::max_size;
    using MyVector<T>::resize;

    // Бинарный поиск элемента
    int q_find(const T& element) const {
        int left = 0;
        int right = static_cast<int>(size) - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (pdata[mid] == element) {
                return mid; // Нашли элемент
            }
            if (pdata[mid] < element) {
                left = mid + 1; // Ищем в правой части
            } else {
                right = mid - 1; // Ищем в левой части
            }
        }
        return -1; // Элемент не найден
    }

public:
    // Проверка наличия элемента
    bool is_element(const T& element) const {
        return q_find(element) != -1;
    }

    // Добавление элемента (с сохранением сортировки)
    void add_element(const T& element) {
        if (!is_element(element)) { // Только уникальные элементы
            MyVector<T>::add_element(element); // Добавляем в конец
            this->sort(); // Сортируем массив
        }
    }

    // Удаление элемента
    void delete_element(const T& element) {
        int index = q_find(element); // Находим индекс
        if (index != -1) {
            MyVector<T>::delete_element(static_cast<size_t>(index));
        }
    }

    // Оператор объединения множеств
    MySet& operator+=(const MySet& other) {
        for (size_t i = 0; i < other.size; ++i) {
            this->add_element(other.pdata[i]); // Добавляем все элементы
        }
        return *this;
    }

    // Оператор пересечения множеств
    MySet& operator*=(const MySet& other) {
        MySet<T> temp;
        for (size_t i = 0; i < size; ++i) {
            if (other.is_element(pdata[i])) {
                temp.add_element(pdata[i]); // Только общие элементы
            }
        }
        *this = temp;
        return *this;
    }

    // Оператор разности множеств
    MySet& operator-=(const MySet& other) {
        for (size_t i = 0; i < other.size; ++i) {
            this->delete_element(other.pdata[i]); // Удаляем общие элементы
        }
        return *this;
    }

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const MySet& set) {
        os << "{";
        for (size_t i = 0; i < set.size; ++i) {
            os << set.pdata[i];
            if (i != set.size - 1) {
                os << ", ";
            }
        }
        os << "}";
        return os;
    }

    // Операторы объединения, пересечения и разности
    friend MySet operator+(const MySet& a, const MySet& b) {
        MySet result = a;
        result += b;
        return result;
    }

    friend MySet operator*(const MySet& a, const MySet& b) {
        MySet result = a;
        result *= b;
        return result;
    }

    friend MySet operator-(const MySet& a, const MySet& b) {
        MySet result = a;
        result -= b;
        return result;
    }

    // Оператор сравнения множеств
    friend bool operator==(const MySet& a, const MySet& b) {
        if (a.size != b.size) return false;
        for (size_t i = 0; i < a.size; ++i) {
            if (a.pdata[i] != b.pdata[i]) {
                return false;
            }
        }
        return true;
    }
};

// Специализация вывода для char*

template <typename T>
std::ostream& operator<<(std::ostream& os, const MySet<char*>& set) {
    os << "{";
    for (size_t i = 0; i < set.MyVector<T>::get_size(); ++i) {
        os << "\"" << set[i] << "\"";
        for (size_t i = 0; i < set.MyVector<T>::get_size(); ++i) {
            os << ", ";
        }
    }
    os << "}";
    return os;
}

int main() {
    // Тестирование с целыми числами
    MySet<int> set1;
    set1.add_element(5);
    set1.add_element(1);
    set1.add_element(4);
    set1.add_element(6);
    
    MySet<int> set2;
    set2.add_element(4);
    set2.add_element(1);
    set2.add_element(3);
    set2.add_element(2);
    
    std::cout << "Set1: " << set1 << std::endl;
    std::cout << "Set2: " << set2 << std::endl;
    
    std::cout << "Union: " << set1 + set2 << std::endl;
    std::cout << "Intersection: " << set1 * set2 << std::endl;
    std::cout << "Difference: " << set1 - set2 << std::endl;
    
    // Тестирование со строками
    MySet<char*> set3;
    set3.add_element("banana");
    set3.add_element("apple");
    set3.add_element("orange");
    
    MySet<char*> set4;
    set4.add_element("kiwi");
    set4.add_element("banana");
    set4.add_element("apple");
    
    std::cout << "\nSet3: " << set3 << std::endl;
    std::cout << "Set4: " << set4 << std::endl;
    
    std::cout << "Union: " << set3 + set4 << std::endl;
    std::cout << "Intersection: " << set3 * set4 << std::endl;
    std::cout << "Difference: " << set3 - set4 << std::endl;
    
    return 0;
}