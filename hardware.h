
class hardware {
public:
    // Функция-член для доступа к единственному экземпляру
    static hardware* getInstance();
 
    // Наполняем полезным функционалом, как и любой другой класс
    bool isHardwareInit();
 
private:
    // Объявляем конструктор закрытым, чтобы нельзя было
    // создавать экземпляры класса извне
    hardware();
    bool stateHardwareInit;
};