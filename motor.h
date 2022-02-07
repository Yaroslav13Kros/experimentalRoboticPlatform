
enum Type_Motor_Drive 
{
    MotorDrive_DC,
    MotorDrive_AC,
};

class MotorDriver
{
public:
    virtual void rotationForward(void) = 0;
    virtual void rotationBack(void) = 0;
    virtual void stop(void) = 0;
    virtual void block(void) = 0;
    virtual ~MotorDriver()
    {
        
    }
    static MotorDriver* createMotorDrive(Type_Motor_Drive type);
};


class DCMotorDrive:public MotorDriver
{
private:
    int setDirPin1;
    int setDirPin2;
    int pwmPin;
public:
    DCMotorDrive(int setDirPin1, int setDirPin2, int pwmPin);
    void rotationForward(void) override;
    void rotationBack(void) override;
    void stop(void) override ;
    void block(void) override;

};