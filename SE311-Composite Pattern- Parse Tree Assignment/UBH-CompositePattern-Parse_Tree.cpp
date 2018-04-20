#include <cstdlib>
#include <iostream>
#include <vector>
//Umutcan Berk HASRET
using namespace std;

// COMPOSITE element
class CompositeElement {
public:
	virtual ~CompositeElement(){};
	virtual void Add(CompositeElement* d) {};
	virtual string Display() {};
	string getName() {return name;};
	virtual int getCount(){};
	virtual CompositeElement *get(int){};
	virtual void Delete() {};
	virtual int solveExpression(string a) {};
	string str;
protected:
	CompositeElement(string name) :name(name) {};
private:
	string name;
};

//Abstract Iterator
class AbstractIterator {
public:
	virtual void First() = 0;
	virtual void Next() = 0;
    virtual bool IsDone () const = 0;
	virtual CompositeElement* CurrentItem() const = 0 ;
protected:
	AbstractIterator(){};
};

//Composite iterator
class NodeIterator : public AbstractIterator {
public:
	NodeIterator(CompositeElement *composite) :
		_composite(composite), _current(0) {
	}
	void First()
	{
	    _current = 0;
    };
    void Next()
    {
        _current++;
    };
    CompositeElement* CurrentItem() const
    {
		return (IsDone()?NULL:_composite->get(_current));
	};
	bool IsDone() const
	{
		return _current >= _composite->getCount();
	};
private:
	CompositeElement *_composite;
	int _current;
};

//Composite Element "Node"
class Node : public CompositeElement {

public:
	Node(string name) : CompositeElement(name) {};
	CompositeElement *get(int index) {return elements[index];};
	int getCount() {return elements.size();};
	void Add(CompositeElement* d) {elements.push_back(d);};
    int solveExpression(string a);

    void Delete() {
        CompositeElement *temp;
        NodeIterator *i = CreateIterator();
		for (i->First(); !i->IsDone(); i->Next()) {
			i->CurrentItem()->Delete();
			delete i->CurrentItem();
		}
		delete i;
	}

	string Display() {

		NodeIterator *i = CreateIterator();

		for (i->First(); !i->IsDone(); i->Next())
            this->str+=i->CurrentItem()->Display();
            delete i;
            return str;
	}
	NodeIterator* CreateIterator() {
		return new NodeIterator(this);
    }

private:
	vector<CompositeElement*> elements;

};

//Primitive Element "Leaf"
class Leaf: public CompositeElement {
 public:
	Leaf(string name) : CompositeElement(name) {};
	string Display() {
        cout<< getName();
		return getName();
	}
};
/*
//To test SolveExpressions functionality.
void printintvector(vector<int> temp){
    for(int i=0;i<temp.size();i++){
        cout<<temp.at(i)<<", ";
    }
    cout<<endl;
}
//To test SolveExpressions functionality.
void printcharvector(vector<char> temp){
    for(int i=0;i<temp.size();i++){
        cout<<temp.at(i)<<", ";
    }
    cout<<endl;
}
*/

//
int Node :: solveExpression(string a){
    int result;
    vector<int> numbers;
    vector<char> operators;
    numbers.clear();
    operators.clear();
    for(int i=0 ; i<a.length() ; i+=2 )
       numbers.push_back(a[i]-'0');     /*We have stored leafs as strings at the beginning.Using -'0' will provide an integer over a char.
                                        Otherwise we will get mathematical errors due to chars being in ASCII form*/
    for(int i=1 ; i<a.length() ; i+=2 )
        operators.push_back(a[i]);

//First loop created for checking if there is any mathematical operations privilege.
    for(int i=0; i<operators.size(); i++)
    {
        if(operators.at(i) == '*'){
            result= numbers.at(i)*numbers.at(i+1);
            numbers.erase(numbers.begin()+i);
            numbers.at(i)=result;
            operators.erase(operators.begin()+i);
            i--;            // Iterator 'i' keeps growing while size of operators is shrinking. Which causes a logic error.
        }
        if(operators.at(i) == '/'){
            result= numbers.at(i)/numbers.at(i+1);
            numbers.erase(numbers.begin()+i);
            numbers.at(i)=result;
            operators.erase(operators.begin()+i);
            i--;
        }

    }

    for(int i=0; i<operators.size(); i++)
    {
        if(operators.at(i) == '+'){
            result= numbers.at(i)+numbers.at(i+1);
            numbers.erase(numbers.begin()+i);
            numbers.at(i)=result;
            operators.erase(operators.begin()+i);
            i--;            // Iterator i keeps growing while size of operators is shrinking. Which causes a logic error.
        }
        if(operators.at(i) == '-'){
            result= numbers.at(i)-numbers.at(i+1);
            numbers.erase(numbers.begin()+i);
            numbers.at(i)=result;
            operators.erase(operators.begin()+i);
            i--;
      }

    }
    return numbers.at(0);
}


int main()
{
    cout<<"First Parse Tree: " << endl << endl << endl;
    CompositeElement* root = new Node("<expression>");
	CompositeElement* expL = new Node("<expL>");
	CompositeElement* termL= new Node("<termL>");
	CompositeElement* termR= new Node("<termR>");
	CompositeElement* termRL = new Node("<termRL>");
	CompositeElement* constl = new Node("<constL>");
	CompositeElement* constrl = new Node("<constRL>");
	CompositeElement* constrr = new Node("<constRR>");
	root->Add(expL);
	root->Add(new Leaf("-"));
	root->Add(termR);
	expL->Add(termL);
	termL->Add(constl);
	constl->Add(new Leaf("5"));
	termR->Add(termRL);
	termR->Add(new Leaf("/"));
	termR->Add(constrr);
	constrr->Add(new Leaf("2"));
	termRL->Add(constrl);
	constrl->Add(new Leaf("4"));


    root->Display();
    cout<<endl<<endl;
    root->Display();
    cout<<" = "<<root->solveExpression(root->str)<<endl;
    cout<<endl;
    root->Delete();

    cout<<"-------------------------------------------"<<endl;
    cout<<endl;

    cout<<"Second Parse Tree: " << endl << endl << endl;
    CompositeElement* root1 = new Node("<expression>");
    CompositeElement* expL1 = new Node("<expL>");
    CompositeElement* expLL = new Node("<expLL>");
    CompositeElement* termL1 = new Node("<termL>");
    CompositeElement* constL = new Node("<constL>");
    CompositeElement* termLR = new Node("<termLR>");
    CompositeElement* constLR = new Node("<constLR>");
    CompositeElement* termRR = new Node("<termR>");
    CompositeElement* constR = new Node("<constR>");
    root1->Add(expL1);
    root1->Add(new Leaf("-"));
    root1->Add(termRR);
    expL1->Add(expLL);
    expL1->Add(new Leaf("-"));
    expL1->Add(termLR);
    expLL->Add(termL1);
    termL1->Add(constL);
    constL->Add(new Leaf("4"));
    termLR->Add(constLR);
    constLR->Add(new Leaf("5"));
    termRR->Add(constR);
    constR->Add(new Leaf("2"));

    root1->Display();
    cout<<endl<<endl;
    root1->Display();
    cout<<" = " << root1->solveExpression(root1->str)<<endl;
    cout<<endl;
    root1->Delete();
}

