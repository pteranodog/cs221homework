// Sort.h : The base class header for all Sort classes 
// for Program 5
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach 

class Sort
{
    private:
        bool showWork = false;
    public:
        Sort();
        ~Sort();
        void SetShowWork(bool);
        bool GetShowWork();
        virtual void Sorted(int array[], int len) = 0;
        virtual void Print(int array[], int len) = 0;
};