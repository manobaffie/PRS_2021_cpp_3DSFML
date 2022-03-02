
class IEngine
{
    public:
        IEngine() = default;
        virtual ~IEngine() = default;

        virtual void draw() = 0;
};
