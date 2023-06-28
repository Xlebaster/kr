#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>

using namespace sf;


#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

class Virus // Абстрактный класс вирус
{
protected:
    std::string strain; // Штамм вируса. Например "Альфа", "Бета", "Омикрон".
    std::string name; // Название вируса
    int numInfected; // Количество зараженных людей
    int propagationPerSecond; // Шанс распространения
    double lethality; // Летальность
public:
    //Virus(); // Конструктор
    Virus(std::string n, std::string s, int i, int p, double l) : name(n), strain(s), numInfected(i), propagationPerSecond(p), lethality(l) {} // Конструктор с параметрами
    //virtual ~Virus() = 0 {}; // Деструктор
    void spread(int time); // Метод, в котором вирус распространяется
    virtual void mutate() = 0; // Метод, в коротом вирус мутирует
    virtual void cure() = 0; // Метод, в котором вирус ослабевает
    //void getInfo(); // Метод, выводящий в виде строки всю информацию об объекте – тип, имена и значения полей.
    std::string getName() { return name; } // Метод, выводящий имя данного класса
    std::string getStrain() { return strain; }
    int getNumInfected() { return numInfected; }
    int getPropagationPerSecond() { return propagationPerSecond; }
    double getLethality() { return lethality; }
};

class COVID19 : public Virus // Класс короновирус
{
public:
    //COVID19() : Virus("COVID-19", "Omicron", 10, 2, 0.03) {} // Конструктор вызывает конструктор базового класса
    COVID19(std::string s, int i, double p, double l) : Virus("COVID-19", s, i, p, l) {} // Конструктор с параметрами вызывает конструктор с параметрами базового класса
    //~COVID19() {} // Деструктор
    void mutate() override; // Переопределенный метод мутирования вируса
    void cure() override; // Переопределенный метод ослабевания вируса
    std::string funcCOVID19(); // Собственный метод класса
};

class Influenza : public Virus // Класс грипп
{
public:
    //Influenza() : Virus("Influenza", "Alfa", 100, 1, 0.01) {} // Конструктор вызывает конструктор базового класса
    Influenza(std::string s, int i, double p, double l) : Virus("Influenza", s, i, p, l) {} // Конструктор с параметрами вызывает конструктор с параметрами базового класса
    //~Influenza() {} // Деструктор
    void mutate() override; // Переопределенный метод мутирования вируса
    void cure() override; // Переопределенный метод ослабевания вируса
    std::string funcInfluenza(); // Собственный метод класса
};

class Smallpox : public Virus // Класс оспа
{
public:
    //Smallpox() : Virus("Smallpox", "Beta", 1000, 10, 0.1) {} // Конструктор вызывает конструктор базового класса
    Smallpox(std::string s, int i, double p, double l) : Virus("Smallpox", s, i, p, l) {} // Конструктор с параметрами вызывает конструктор с параметрами базового класса
    //~Smallpox() {} // Деструктор
    void mutate() override; // Переопределенный метод мутирования вируса
    void cure() override; // Переопределенный метод ослабевания вируса
    std::string funcSmallpox(); // Собственный метод класса
};

class Plague : public Virus // Класс чума
{
public:
    //Plague() : Virus("Plague", "Zeta", 1000, 10, 0.1) {} // Конструктор вызывает конструктор базового класса
    Plague(std::string s, int i, double p, double l) : Virus("Plague", s, i, p, l) {} // Конструктор с параметрами вызывает конструктор с параметрами базового класса
    //~Plague() {} // Деструктор
    void mutate() override; // Переопределенный метод мутирования вируса
    void cure() override; // Переопределенный метод ослабевания вируса
    std::string funcPlague(); // Собственный метод класса
};

bool isInRange(std::string input);

//vector<Virus*> viruses
bool do1(std::vector<Virus*>& viruses);

bool do2(std::vector<Virus*>& viruses);

void do3(std::vector<Virus*>& viruses);

void do4(std::vector<Virus*>& viruses);

void do5(std::vector<Virus*>& viruses);

void do6(std::vector<Virus*>& viruses);



int main()
{
    std::vector<Virus*> viruses; // Создаем пустой массив указателей на базовый класс
    //COVID19 v("Omicron", 10, 2, 0.03);
    //COVID19* point_v = &v;
    //viruses.push_back(point_v);
    //setlocale(LC_ALL, "Russian");
    sf::RenderWindow window(sf::VideoMode(800, 600), L"Вирусы", sf::Style::Default); //  “sf::Style::Default” указывает стиль окна настроен на использование стандартного стиля SFML, но можно указать и другие стили.
    //window.setUnicodeDetails(true);

    // Загрузка шрифта с проверкой
    sf::Font font;
    if (!font.loadFromFile("CyrilicOld.TTF"))
    {
        std::cerr << "Error loading font\n";
        return -1;
    }


    // Настраиваем текст и его нахождение для меню
    sf::Text menu_title("Выберите действие:", font, 24);
    sf::Text text1("1. Добавить новый вирус в массив", font, 24);
    sf::Text text2("2. Заставить вирус распространяться", font, 24);
    sf::Text text3("3. Ослабить вирус", font, 24);
    sf::Text text4("4. Сделать вирус сильнее", font, 24);
    sf::Text text5("5. Вывести все вирусы", font, 24);
    sf::Text text6("6. Выполнить уникальный метод класса", font, 24);
    sf::Text menu_exit("7. Выход", font, 24);
    sf::Text consoleOutput("", font, 24);

    menu_title.setPosition(0, 0);
    text1.setPosition(0, 50);
    text2.setPosition(0, 100);
    text3.setPosition(0, 150);
    text4.setPosition(0, 200);
    text5.setPosition(0, 250);
    text6.setPosition(0, 300);
    menu_exit.setPosition(0, 350);
    consoleOutput.setPosition(0, 400);

    // Для управления цветом пунктов меню
    bool clicked_text1 = false;
    bool clicked_text2 = false;
    bool clicked_text3 = false;
    bool clicked_text4 = false;
    bool clicked_text5 = false;
    bool clicked_text6 = false;
    bool clicked_menu_exit = false;

    // Для перемещения камеры
    sf::View view = window.getView();
    float view_speed = 50.0f;





    while (window.isOpen())
    {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

        // Обработка наведения мышью на пункты меню начало
        if (text1.getGlobalBounds().contains((sf::Vector2f)mouse_pos)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                text1.setFillColor(sf::Color::Red);
                clicked_text1 = true;
                if (do1(viruses))
                {
                    consoleOutput.setString("Новый вирус успешно добавлен");
                    consoleOutput.setFillColor(sf::Color::Green);
                }
                else
                {
                    consoleOutput.setString("Новый вирус не добавлен");
                    consoleOutput.setFillColor(sf::Color::Red);
                }
                clicked_text1 = false;
            }
            else if (!clicked_text1) {
                text1.setFillColor(sf::Color::Green);
            }
        }
        else {
            text1.setFillColor(sf::Color::White);
        }

        if (text2.getGlobalBounds().contains((sf::Vector2f)mouse_pos)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                text2.setFillColor(sf::Color::Red);
                clicked_text2 = true;
                if (do2(viruses))
                {
                    consoleOutput.setString("Вирус распространился");
                    consoleOutput.setFillColor(sf::Color::Green);
                }
                else
                {
                    consoleOutput.setString("Вирус не распространился");
                    consoleOutput.setFillColor(sf::Color::Red);
                }
                clicked_text2 = false;
                //consoleOutput.setString("Вирусы распространены");
                //consoleOutput.setFillColor(sf::Color::Green);
            }
            else if (!clicked_text2) {
                text2.setFillColor(sf::Color::Green);
            }
        }
        else {
            text2.setFillColor(sf::Color::White);
        }

        if (text3.getGlobalBounds().contains((sf::Vector2f)mouse_pos)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                text3.setFillColor(sf::Color::Red);
                clicked_text3 = true;
                do3(viruses);
                consoleOutput.setString("Вирус ослаблен");
                consoleOutput.setFillColor(sf::Color::Green);
            }
            else if (!clicked_text3) {
                text3.setFillColor(sf::Color::Green);
            }
        }
        else {
            text3.setFillColor(sf::Color::White);
        }

        if (text4.getGlobalBounds().contains((sf::Vector2f)mouse_pos)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                text4.setFillColor(sf::Color::Red);
                clicked_text4 = true;
                do4(viruses);
                consoleOutput.setString("Вирус усилен");
                consoleOutput.setFillColor(sf::Color::Green);
            }
            else if (!clicked_text4) {
                text4.setFillColor(sf::Color::Green);
            }
        }
        else {
            text4.setFillColor(sf::Color::White);
        }

        if (text5.getGlobalBounds().contains((sf::Vector2f)mouse_pos)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                text5.setFillColor(sf::Color::Red);
                clicked_text5 = true;
                consoleOutput.setString("");
                do5(viruses);
                clicked_text5 = false;
            }
            else if (!clicked_text5) {
                text5.setFillColor(sf::Color::Green);
            }
        }
        else {
            text5.setFillColor(sf::Color::White);
        }

        if (text6.getGlobalBounds().contains((sf::Vector2f)mouse_pos)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                text6.setFillColor(sf::Color::Red);
                clicked_text6 = true;
                consoleOutput.setString("");
                do6(viruses);
                clicked_text6 = false;
            }
            else if (!clicked_text6) {
                text6.setFillColor(sf::Color::Green);
            }
        }
        else {
            text6.setFillColor(sf::Color::White);
        }

        if (menu_exit.getGlobalBounds().contains((sf::Vector2f)mouse_pos)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                menu_exit.setFillColor(sf::Color::Red);
                clicked_menu_exit = true;
            }
            else if (!clicked_menu_exit) {
                menu_exit.setFillColor(sf::Color::Green);
            }
        }
        else {
            menu_exit.setFillColor(sf::Color::White);
        }
        // Обработка наведения мышью на пункты меню конец

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (clicked_menu_exit)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased) {
                clicked_text1 = false;
                clicked_text2 = false;
                clicked_text3 = false;
                clicked_text4 = false;
                clicked_text5 = false;
                clicked_text6 = false;
                clicked_menu_exit = false;
            }
            /*
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    view.move(0.0f, -view_speed);
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    view.move(0.0f, view_speed);
                }
                else if (event.key.code == sf::Keyboard::Left) {
                    view.move(-view_speed, 0.0f);
                }
                else if (event.key.code == sf::Keyboard::Right) {
                    view.move(view_speed, 0.0f);
                }
            }
            */
        }

        window.clear();

        window.setView(view);


        window.draw(menu_title);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(text5);
        window.draw(text6);
        window.draw(menu_exit);
        window.draw(consoleOutput);
        // Выводим на экран
        window.display();
    }

    return 0;
}


bool isInRange(std::string input) {
    // Конвертируем строку в число с плавающей точкой
    input[1] = '.';
    double num = stod(input);

    // Проверяем, что число находится в диапазоне (0, 1)
    if (num > 0.0 && num < 1.0) {
        return true;
    }
    else {
        return false;
    }
}
//vector<Virus*> viruses
bool do1(std::vector<Virus*>& viruses)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), L"Добавление вируса", sf::Style::Default);

    sf::Font font;
    if (!font.loadFromFile("CyrilicOld.TTF"))
    {
        std::cerr << "Error loading font\n";
        return false;
    }


    const int FIELD_WIDTH = 200;
    const int FIELD_HEIGHT = 30;

    sf::Text title1("Введите штамм вируса", font, 20);
    title1.setFillColor(sf::Color::White);
    title1.setPosition(50, 200);

    sf::RectangleShape field1(sf::Vector2f(FIELD_WIDTH, FIELD_HEIGHT));
    field1.setFillColor(sf::Color::Transparent);
    field1.setOutlineColor(sf::Color::White);
    field1.setOutlineThickness(2);
    field1.setPosition(50, 250);

    sf::Text input1("", font, 24);
    input1.setFillColor(sf::Color::White);
    input1.setPosition(50, 250);

    sf::Text info1("Заглавные латинские буквы и цифры", font, 16);
    info1.setFillColor(sf::Color::White);
    info1.setPosition(50, 300);

    sf::Text title2("Введите число зараженных", font, 20);
    title2.setFillColor(sf::Color::White);
    title2.setPosition(450, 200);

    sf::RectangleShape field2(sf::Vector2f(FIELD_WIDTH, FIELD_HEIGHT));
    field2.setFillColor(sf::Color::Transparent);
    field2.setOutlineColor(sf::Color::White);
    field2.setOutlineThickness(2);
    field2.setPosition(450, 250);

    sf::Text input2("", font, 24);
    input2.setFillColor(sf::Color::White);
    input2.setPosition(450, 250);

    sf::Text info2("Натуральное число или ноль", font, 16);
    info2.setFillColor(sf::Color::White);
    info2.setPosition(450, 300);

    sf::Text title3("Введите число распространений за время", font, 20);
    title3.setFillColor(sf::Color::White);
    title3.setPosition(50, 400);

    sf::RectangleShape field3(sf::Vector2f(FIELD_WIDTH, FIELD_HEIGHT));
    field3.setFillColor(sf::Color::Transparent);
    field3.setOutlineColor(sf::Color::White);
    field3.setOutlineThickness(2);
    field3.setPosition(50, 450);

    sf::Text input3("", font, 24);
    input3.setFillColor(sf::Color::White);
    input3.setPosition(50, 450);

    sf::Text info3("Натуральное число или ноль", font, 16);
    info3.setFillColor(sf::Color::White);
    info3.setPosition(50, 500);

    sf::Text title4("Введите летальность", font, 20);
    title4.setFillColor(sf::Color::White);
    title4.setPosition(450, 400);

    sf::RectangleShape field4(sf::Vector2f(FIELD_WIDTH, FIELD_HEIGHT));
    field4.setFillColor(sf::Color::Transparent);
    field4.setOutlineColor(sf::Color::White);
    field4.setOutlineThickness(2);
    field4.setPosition(450, 450);

    sf::Text input4("0,", font, 24);
    input4.setFillColor(sf::Color::White);
    input4.setPosition(450, 450);

    sf::Text info4("Рациональное число, лежащее в интервале (0;1)", font, 16);
    info4.setFillColor(sf::Color::White);
    info4.setPosition(450, 500);

    bool active1 = false;
    bool active2 = false;
    bool active3 = false;
    bool active4 = false;



    sf::Text virus("Коронавирус", font, 30);
    virus.setFillColor(sf::Color::White);
    virus.setPosition(50, 50);

    sf::Text flu("Грипп", font, 30);
    flu.setFillColor(sf::Color::White);
    flu.setPosition(450, 50);

    sf::Text smallpox("Оспа", font, 30);
    smallpox.setFillColor(sf::Color::White);
    smallpox.setPosition(50, 100);

    sf::Text plague("Чума", font, 30);
    plague.setFillColor(sf::Color::White);
    plague.setPosition(450, 100);

    bool virusSelected = false;
    bool fluSelected = false;
    bool smallpoxSelected = false;
    bool plagueSelected = false;

    sf::Text choose("Выберите какой вирус создать", font, 24);
    choose.setFillColor(sf::Color::White);
    choose.setPosition(0, 0);

    sf::Text input("Выберите какой вирус создать", font, 24);
    input.setFillColor(sf::Color::White);
    input.setPosition(0, 150);

    sf::Text ready("Готово", font, 30);
    ready.setFillColor(sf::Color::White);
    ready.setPosition(450, 550);

    sf::Text cancel("Отмена", font, 30);
    cancel.setFillColor(sf::Color::White);
    cancel.setPosition(50, 550);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return false;
            }

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
                return false;
            }

            else if (event.type == sf::Event::MouseButtonPressed) // Определение, какое поле было кликнуто для активации
            {
                sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
                if (field1.getGlobalBounds().contains(mousePos))
                {
                    active1 = true;
                    active2 = false;
                    active3 = false;
                    active4 = false;
                }
                else if (field2.getGlobalBounds().contains(mousePos))
                {
                    active1 = false;
                    active2 = true;
                    active3 = false;
                    active4 = false;
                }
                else if (field3.getGlobalBounds().contains(mousePos))
                {
                    active1 = false;
                    active2 = false;
                    active3 = true;
                    active4 = false;
                }
                else if (field4.getGlobalBounds().contains(mousePos))
                {
                    active1 = false;
                    active2 = false;
                    active3 = false;
                    active4 = true;
                }
                else if (virus.getGlobalBounds().contains(mousePos))
                {
                    virusSelected = true;
                    fluSelected = false;
                    smallpoxSelected = false;
                    plagueSelected = false;
                }
                else if (flu.getGlobalBounds().contains(mousePos))
                {
                    virusSelected = false;
                    fluSelected = true;
                    smallpoxSelected = false;
                    plagueSelected = false;
                }
                else if (smallpox.getGlobalBounds().contains(mousePos))
                {
                    virusSelected = false;
                    fluSelected = false;
                    smallpoxSelected = true;
                    plagueSelected = false;
                }
                else if (plague.getGlobalBounds().contains(mousePos))
                {
                    virusSelected = false;
                    fluSelected = false;
                    smallpoxSelected = false;
                    plagueSelected = true;
                }
                else if (ready.getGlobalBounds().contains(mousePos))
                {
                    bool canCreate = true;

                    if (!(virusSelected || fluSelected || smallpoxSelected || plagueSelected)) // Если ни один не выбран
                    {
                        choose.setFillColor(sf::Color::Red);
                        canCreate = false;
                    }
                    else
                        choose.setFillColor(sf::Color::White);

                    if (input1.getString() == "")
                    {
                        info1.setFillColor(sf::Color::Red);
                        canCreate = false;
                    }
                    else
                        info1.setFillColor(sf::Color::White);

                    if (input2.getString() == "")
                    {
                        info2.setFillColor(sf::Color::Red);
                        canCreate = false;
                    }
                    else
                        info2.setFillColor(sf::Color::White);

                    if (input3.getString() == "")
                    {
                        info3.setFillColor(sf::Color::Red);
                        canCreate = false;
                    }
                    else
                        info3.setFillColor(sf::Color::White);

                    if (isInRange(input4.getString()))
                        info4.setFillColor(sf::Color::White);
                    else
                    {
                        info4.setFillColor(sf::Color::Red);
                        canCreate = false;
                    }

                    if (canCreate)
                    {
                        // Добавляем в массив
                        std::string strain = input1.getString();
                        std::string numInfected = input2.getString();
                        std::string propPerSecond = input3.getString();
                        std::string lethality = input4.getString();
                        lethality[1] = '.';
                        if (virusSelected)
                        {
                            COVID19* covid = new COVID19(strain, std::stoi(numInfected), std::stoi(propPerSecond), std::stod(lethality));
                            if (covid == nullptr)
                                return false;
                            viruses.push_back(covid);
                        }
                        else if (fluSelected)
                        {
                            Influenza* flu = new Influenza(strain, std::stoi(numInfected), std::stoi(propPerSecond), std::stod(lethality));
                            if (flu == nullptr)
                                return false;
                            viruses.push_back(flu);
                        }
                        else if (smallpoxSelected)
                        {
                            Smallpox* smallpox = new Smallpox(strain, std::stoi(numInfected), std::stoi(propPerSecond), std::stod(lethality));
                            if (smallpox == nullptr)
                                return false;
                            viruses.push_back(smallpox);
                        }
                        else if (plagueSelected)
                        {
                            Plague* plague = new Plague(strain, std::stoi(numInfected), std::stoi(propPerSecond), std::stod(lethality));
                            if (plague == nullptr)
                                return false;
                            viruses.push_back(plague);
                        }
                        return true;
                    }
                }

                else if (cancel.getGlobalBounds().contains(mousePos))
                {
                    window.close();
                    return false;
                }
            }

            else if (event.type == sf::Event::TextEntered) // Ввод текста в активное поле
            {
                if (active1)
                {
                    if (event.text.unicode == '\b' && !input1.getString().isEmpty()) // Обработка символа "backspace" в поле ввода
                    {
                        input1.setString(input1.getString().substring(0, input1.getString().getSize() - 1));
                    }
                    else if ((event.text.unicode >= 'A' && event.text.unicode <= 'Z' || event.text.unicode >= '0' && event.text.unicode <= '9') && input1.getString().getSize() < 8) // Добавление символа в поле ввода
                    {
                        input1.setString(input1.getString() + static_cast<char>(event.text.unicode));
                    }
                }
                else if (active2)
                {
                    if (event.text.unicode == '\b' && !input2.getString().isEmpty())
                    {
                        input2.setString(input2.getString().substring(0, input2.getString().getSize() - 1));
                    }
                    else if (event.text.unicode >= '0' && event.text.unicode <= '9' && input2.getString().getSize() < 8)
                    {
                        std::string input_str = input2.getString();
                        if (input_str[0] != '0')
                        {
                            input_str += static_cast<char>(event.text.unicode);
                            input2.setString(input_str);
                        }
                    }
                }
                else if (active3)
                {
                    if (event.text.unicode == '\b' && !input3.getString().isEmpty())
                    {
                        input3.setString(input3.getString().substring(0, input3.getString().getSize() - 1));
                    }
                    else if (event.text.unicode >= '0' && event.text.unicode <= '9' && input3.getString().getSize() < 8)
                    {
                        std::string input_str = input3.getString();
                        if (input_str[0] != '0')
                        {
                            input_str += static_cast<char>(event.text.unicode);
                            input3.setString(input_str);
                        }
                    }
                }
                else if (active4)
                {
                    if (event.text.unicode == '\b' && !input4.getString().isEmpty() && (input4.getString().getSize() > 2))
                    {
                        input4.setString(input4.getString().substring(0, input4.getString().getSize() - 1));
                    }
                    else if (event.text.unicode >= '0' && event.text.unicode <= '9' && input4.getString().getSize() < 8)
                    {
                        input4.setString(input4.getString() + static_cast<char>(event.text.unicode));
                    }
                }

            }

            else if (event.type == sf::Event::MouseMoved)
            {
                sf::FloatRect bounds1 = cancel.getGlobalBounds();
                if (bounds1.contains(event.mouseMove.x, event.mouseMove.y))
                {
                    cancel.setFillColor(sf::Color::Red);
                }
                else
                {
                    cancel.setFillColor(sf::Color::White);
                }
                sf::FloatRect bounds2 = ready.getGlobalBounds();
                if (bounds2.contains(event.mouseMove.x, event.mouseMove.y))
                {
                    ready.setFillColor(sf::Color::Green);
                }
                else
                {
                    ready.setFillColor(sf::Color::White);
                }
            }

            // Обновление текста ввода на активном поле
            if (active1)
            {
                field1.setOutlineColor(sf::Color::Green);
            }
            else
            {
                field1.setOutlineColor(sf::Color::White);
            }
            if (active2)
            {
                field2.setOutlineColor(sf::Color::Green);
            }
            else
            {
                field2.setOutlineColor(sf::Color::White);
            }
            if (active3)
            {
                field3.setOutlineColor(sf::Color::Green);
            }
            else
            {
                field3.setOutlineColor(sf::Color::White);
            }
            if (active4)
            {
                field4.setOutlineColor(sf::Color::Green);
            }
            else
            {
                field4.setOutlineColor(sf::Color::White);
            }

            if (virusSelected)
            {
                virus.setFillColor(sf::Color::Green);
            }
            else
            {
                virus.setFillColor(sf::Color::White);
            }
            if (fluSelected)
            {
                flu.setFillColor(sf::Color::Green);
            }
            else
            {
                flu.setFillColor(sf::Color::White);
            }
            if (smallpoxSelected)
            {
                smallpox.setFillColor(sf::Color::Green);
            }
            else
            {
                smallpox.setFillColor(sf::Color::White);
            }
            if (plagueSelected)
            {
                plague.setFillColor(sf::Color::Green);
            }
            else
            {
                plague.setFillColor(sf::Color::White);
            }
        }

        window.clear(sf::Color::Black);

        window.draw(title1);
        window.draw(field1);
        window.draw(input1);
        window.draw(info1);

        window.draw(title2);
        window.draw(field2);
        window.draw(input2);
        window.draw(info2);

        window.draw(title3);
        window.draw(field3);
        window.draw(input3);
        window.draw(info3);

        window.draw(title4);
        window.draw(field4);
        window.draw(input4);
        window.draw(info4);


        window.draw(virus);
        window.draw(flu);
        window.draw(smallpox);
        window.draw(plague);


        window.draw(cancel);
        window.draw(ready);
        window.draw(choose);
        window.draw(input);

        window.display();
    }
}

bool do2(std::vector<Virus*>& viruses)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), L"Распространение вируса", sf::Style::Default);

    sf::Font font;
    font.loadFromFile("CyrilicOld.TTF");

    const int FIELD_WIDTH = 200;
    const int FIELD_HEIGHT = 30;

    sf::Text title("Введите сколько времени должен распространяться вирус", font, 20);
    title.setFillColor(sf::Color::White);
    title.setPosition(0, 0);

    sf::RectangleShape field(sf::Vector2f(FIELD_WIDTH, FIELD_HEIGHT));
    field.setFillColor(sf::Color::Transparent);
    field.setOutlineColor(sf::Color::White);
    field.setOutlineThickness(2);
    field.setPosition(50, 50);

    sf::Text input("", font, 24);
    input.setFillColor(sf::Color::White);
    input.setPosition(50, 50);

    sf::Text info("Натуральное число или ноль", font, 16);
    info.setFillColor(sf::Color::White);
    info.setPosition(50, 100);

    sf::Text ready("Готово", font, 24);
    ready.setFillColor(sf::Color::White);
    ready.setPosition(0, 150);

    sf::Text cancel("Отмена", font, 24);
    cancel.setFillColor(sf::Color::White);
    cancel.setPosition(0, 200);

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                return false;
            }

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
                return false;
            }

            else if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
                if (ready.getGlobalBounds().contains(mousePos))
                {
                    if (input.getString() == "")
                    {
                        info.setFillColor(sf::Color::Red);
                    }
                    else
                    {
                        std::string input_str = input.getString();
                        for (auto virus : viruses) { // Для всех вирусов вызываем метод распространения с данными введенными от пользователя
                            virus->spread(std::stoi(input_str));
                        }
                        return true;
                    }
                }
                else if (cancel.getGlobalBounds().contains(mousePos))
                {
                    window.close();
                    return false;
                }
            }

            else if (event.type == sf::Event::TextEntered) // Ввод текста в активное поле
            {
                if (event.text.unicode == '\b' && !input.getString().isEmpty())
                {
                    input.setString(input.getString().substring(0, input.getString().getSize() - 1));
                }
                else if (event.text.unicode >= '0' && event.text.unicode <= '9' && input.getString().getSize() < 8) //
                {
                    std::string input_str = input.getString();
                    if (input_str[0] != '0')
                    {
                        input_str += static_cast<char>(event.text.unicode);
                        input.setString(input_str);
                    }
                }
            }
            window.clear(sf::Color::Black);

            window.draw(title);
            window.draw(field);
            window.draw(input);
            window.draw(info);

            window.draw(ready);
            window.draw(cancel);

            window.display();
        }

    }
}

void do3(std::vector<Virus*>& viruses)
{
    for (auto virus : viruses) {
        virus->cure();
    }
}

void do4(std::vector<Virus*>& viruses)
{
    for (auto virus : viruses) {
        virus->mutate();
    }
}



void do5(std::vector<Virus*>& viruses)
{
    sf::RenderWindow window(sf::VideoMode(1200, 600), L"Все вирусы", sf::Style::Default);

    sf::View view = window.getView();
    float view_speed = 50.0f;

    sf::Font font;
    font.loadFromFile("CyrilicOld.TTF");

    sf::Text titleName("НАЗВАНИЕ ВИРУСА", font, 20);
    titleName.setPosition(0, 0);
    titleName.setFillColor(sf::Color::White);

    sf::Text name("", font, 20);
    name.setPosition(0, 50);
    name.setFillColor(sf::Color::White);

    sf::Text titleStain("ШТАММ", font, 20);
    titleStain.setPosition(230, 0);
    titleStain.setFillColor(sf::Color::White);

    sf::Text strain("", font, 20);
    strain.setPosition(230, 50);
    strain.setFillColor(sf::Color::White);

    sf::Text titleNumInfected("ЧИСЛО ЗАРАЖЕННЫХ", font, 20);
    titleNumInfected.setPosition(350, 0);
    titleNumInfected.setFillColor(sf::Color::White);

    sf::Text numInfected("", font, 20);
    numInfected.setPosition(350, 50);
    numInfected.setFillColor(sf::Color::White);

    sf::Text titlePropagationPerSecond("РАСПРОСТРАНЕНИЯ ЗА ВРЕМЯ", font, 20);
    titlePropagationPerSecond.setPosition(650, 0);
    titlePropagationPerSecond.setFillColor(sf::Color::White);

    sf::Text propagationPerSecond("", font, 20);
    propagationPerSecond.setPosition(650, 50);
    propagationPerSecond.setFillColor(sf::Color::White);

    sf::Text titleLethality("ЛЕТАЛЬНОСТЬ", font, 20);
    titleLethality.setPosition(1050, 0);
    titleLethality.setFillColor(sf::Color::White);

    sf::Text lethality("", font, 20);
    lethality.setPosition(1050, 50);
    lethality.setFillColor(sf::Color::White);

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();

            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    view.move(0.0f, -view_speed);
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    view.move(0.0f, view_speed);
                }
            }
        }

        window.clear(sf::Color::Black);

        window.setView(view);

        window.draw(titleName);
        window.draw(titleStain);
        window.draw(titleNumInfected);
        window.draw(titlePropagationPerSecond);
        window.draw(titleLethality);


        for (int i = 0; i < viruses.size(); i++)
        {
            std::string Name = viruses[i]->getName();

            if (Name == "COVID-19")
                Name = "Коронавирус";
            else if (Name == "Influenza")
                Name = "Грипп";
            else if (Name == "Smallpox")
                Name = "Оспа";
            else if (Name == "Plague")
                Name = "Чума";

            std::string Strain = viruses[i]->getStrain();
            std::string NumInfected = std::to_string(viruses[i]->getNumInfected());
            std::string PropagationPerSecond = std::to_string(viruses[i]->getPropagationPerSecond());
            std::string Lethality = std::to_string(viruses[i]->getLethality());

            name.setPosition(0, 50 + 50 * i);
            name.setFillColor(sf::Color::White);
            name.setString(Name);

            strain.setPosition(230, 50 + 50 * i);
            strain.setFillColor(sf::Color::White);
            strain.setString(Strain);

            numInfected.setPosition(350, 50 + 50 * i);
            numInfected.setFillColor(sf::Color::White);
            numInfected.setString(NumInfected);

            propagationPerSecond.setPosition(650, 50 + 50 * i);
            propagationPerSecond.setFillColor(sf::Color::White);
            propagationPerSecond.setString(PropagationPerSecond);

            lethality.setPosition(1050, 50 + 50 * i);
            lethality.setFillColor(sf::Color::White);
            lethality.setString(Lethality);


            window.draw(name);
            window.draw(strain);
            window.draw(numInfected);
            window.draw(propagationPerSecond);
            window.draw(lethality);
        }



        window.display();
    }
}

void do6(std::vector<Virus*>& viruses)
{
    sf::RenderWindow window(sf::VideoMode(1200, 600), L"Уникальные методы вирусов", sf::Style::Default);

    sf::View view = window.getView();
    float view_speed = 50.0f;

    sf::Font font;
    font.loadFromFile("CyrilicOld.TTF");

    sf::Text info("", font, 24);
    info.setPosition(0, 0);
    info.setFillColor(sf::Color::White);

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();

            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    view.move(0.0f, -view_speed);
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    view.move(0.0f, view_speed);
                }
            }
        }

        window.clear(sf::Color::Black);

        window.setView(view);
        int i = 0;
        for (auto virus : viruses)
        {
            if (virus->getName() == "COVID-19") // Если этот вирус - коронавирус
            {
                COVID19* v = dynamic_cast<COVID19*>(virus); // Создаем указатель на короновирус
                if (v != nullptr) // Если получилось создать указатель на короновирус
                {
                    info.setString(v->funcCOVID19()); // Вызваем собственный метод короновируса
                }
            }

            if (virus->getName() == "Influenza") // Если этот вирус - грипп
            {
                Influenza* v = dynamic_cast<Influenza*>(virus); // Создаем указатель на грипп
                if (v != nullptr) // Если получилось создать указатель на грипп
                {
                    info.setString(v->funcInfluenza()); // Вызваем собственный метод гриппа
                }
            }

            if (virus->getName() == "Smallpox") // Если этот вирус - оспа
            {
                Smallpox* v = dynamic_cast<Smallpox*>(virus); // Создаем указатель на оспу
                if (v != nullptr)  // Если получилось создать указатель на оспу
                {
                    info.setString(v->funcSmallpox()); // Вызваем собственный метод оспы
                }
            }

            if (virus->getName() == "Plague")  // Если этот вирус - чума
            {
                Plague* v = dynamic_cast<Plague*>(virus); // Создаем указатель на чуму
                if (v != nullptr)  // Если получилось создать указатель на чуму
                {
                    info.setString(v->funcPlague()); // Вызваем собственный метод чумы
                }
            }

            info.setPosition(0, i * 50);

            i++;

            window.draw(info);
        }
        window.display();
    }
}

/*
Virus::Virus()
{
}
*/

void Virus::spread(int time)
{
    numInfected += propagationPerSecond * time;
}
/*
void Virus::getInfo()
{
    //std::cout << setw(16) << left << name << setw(10) << strain << setw(17) << numInfected << setw(26) << propagationPerSecond << setw(12) << lethality << std::endl;
    //std::cout << "Тип " + getName() + ", strain " + strain + ", name " + name + ", numInfected " + to_std::string(numInfected) + ", propagationPerSecond " + to_std::string(propagationPerSecond) + ", lethality " + to_std::string(lethality) << std::endl;
}
*/
void COVID19::mutate()
{
    propagationPerSecond += 10;
}

void COVID19::cure()
{
    propagationPerSecond = MAX(propagationPerSecond - 10, 0);
}

std::string COVID19::funcCOVID19()
{
    return  "COVID19 появился в 2019 году в Ухани.";
}

void Influenza::mutate()
{
    lethality = MIN(lethality + 0.01, 0.99);
}

void Influenza::cure()
{
    lethality = MAX(lethality - 0.01, 0);
}

std::string Influenza::funcInfluenza()
{
    return "Чтобы вылечиться от гриппа нужно: соблюдать послельный режим, обильно пить теплое питьё.";
}

void Smallpox::mutate()
{
    lethality = MIN(lethality + 0.01, 0.99);
    propagationPerSecond += 10;
}

void Smallpox::cure()
{
    lethality = MAX(lethality - 0.01, 0);
    propagationPerSecond = MAX(propagationPerSecond - 10, 0);
}

std::string Smallpox::funcSmallpox()
{
    return "14 мая 1796 года Эдвард Дженнер изобрел вакцину от оспы.";
}

void Plague::mutate()
{
    lethality = MIN(lethality + 0.01, 0.99);
    propagationPerSecond += 10;
}

void Plague::cure()
{
    numInfected = MAX(0, numInfected - 100);
    lethality = MAX(lethality - 0.01, 0);
    propagationPerSecond = MAX(propagationPerSecond - 10, 0);
}

std::string Plague::funcPlague()
{
    return "Чтобы не заболеть чумой: тщательно мыть руки перед едой, употреблять в пищу безопасную питьевую воду.";
}
