#ifndef __EXAMPLE__
#define __EXAMPLE__
	
class Example {
		
private:
	int _data;
	static int size;
	int id;
	// (1)
			
public:
	
	Example(int data);
	void getData();
	~Example();

};
		
#endif