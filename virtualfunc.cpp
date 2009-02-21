#include <stdio.h>

class parent
{
  protected:
    char version;
  public:
    parent() { version = 'A'; }
    virtual void print()
    {
      printf("\nThe parent. Version %c", version);
    }
};

class derived1 : public parent
{
  private:
    int info;
  public:
    derived1(int number)
    {
      info = number;
      version = '1';
    }
    void print() 
    {
      printf("\nDerived 1 info: %d. Version %c", info, version);
    }
};

class derived2 : public parent
{
  private:
    int info;
  public:
    derived2(int number)
    {
      info = number;
    }
    void print() 
    {
      printf("\nDerived 2 info: %d. Version %c", info, version);
    }
};

class derived3 : public derived1
{
  private:
    int info;
  public:
    derived3(int number) : derived1(number) 
    {
      info = number;
      version = '3';
    }
    void print()
    {
      printf("\nDerived 3 info: %d. Version %c", info, version);
    }
};

void print_info(parent *info_holder)
{
  info_holder->print();
}

main() {
  parent b;
  derived1 d1(3);
  derived2 d2(15);
  derived3 d3(-565);

  print_info(&b);
  print_info(&d1);
  print_info(&d2);
  print_info(&d3);
}
