namespace space_invaders::game {

class Object
{
public:
    Object(Object* = nullptr);
    ~Object();

private:
    Object* m_parent{nullptr};
};

}
