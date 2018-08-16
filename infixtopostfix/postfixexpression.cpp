/* stack ashiglan postfix ilephiilel ashiglan bodoh*/

#include<iostream>
#include<stack>
#include<string>

using namespace std;

// Function to evaluate Postfix expression and return output
// postfix expressionii garaltiin up dung hapuulah
int EvaluatePostfix(string expression);

// Function to perform an operation and return output.
//tuhain functionii uu operationiig yvuukah
int PerformOperation(char operation, int operand1, int operand2);

// Function to verify whether a character is operator symbol or not.
// tyhain functionii temdegt ni operator in operand mon esehiig shalgah
bool IsOperator(char C);

// Function to verify whether a character is numeric digit.
//fynction ni toon utgatai esehiig shalgah
bool IsNumericDigit(char C);
/* main */
int main()
{
	string expression;
	cout<<"Enter Postfix Expression \n";
	getline(cin,expression);
	int result = EvaluatePostfix(expression);
	cout<<"Output = "<<result<<"\n";
}

// postfix ilehphiill garaltiin up dung hapuulah
int EvaluatePostfix(string expression)
{
	// C++ standart library gas stack iig zaplah
	stack<int> S;

	for(int i = 0;i< expression.length();i++) {

		//temdeglegee bypiig zuun talaas shalgah`
		//  hepvee temdegt bol hyzzgaaplaj, ugui bol upgeljluuleh
		if(expression[i] == ' ' || expression[i] == ',') continue;

		// hervee temdegt ni operator bol 2elementiig stack ees gargaj, uildliig hiin butsaah
		else if(IsOperator(expression[i])) {
			// 2 operand uildel hiine
			int operand2 = S.top(); S.pop();
			int operand1 = S.top(); S.pop();
			// uildliig guitsetgeh
			int result = PerformOperation(expression[i], operand1, operand2);
			//up dung stackd butsaan hiih
			S.push(result);
		}
		else if(IsNumericDigit(expression[i])){
			// tyhain functionaa stoon utgig zadlah
			// toon ytgatau baih ym bol nemegden opoh.
			int operand = 0;
			while(i<expression.length() && IsNumericDigit(expression[i])) {
				// zuunees bapun tiish haij bgaa uchraas neg opontoi toonoos ehlen olon opontoo toog ushih
				//zov jigleln boloh zuunees bapuun tiishee yvah ba shinee tsipruudiig nemeh.
				operand = (operand*10) + (expression[i] - '0');
				i++;
			}
			// suuld ni tyhain davtaltaas garahdaa toon temdegt es bol togsgld ni tavina
			// i-- shaltgaan ni  dahin davtaltiin tsegen tuuvpiin heseg deer ni nemegdene
			// toon temdegtig algasahgui baij bolohgui
			i--;

			// stack d oerandiig hiih
			S.push(operand);
		}
	}
	// hervee ilephiilel zob bijigleltei baihiin bol , stack d neg element baina.
	return S.top();
}

// tyhain function ni toon opontoi esehiig salgah
bool IsNumericDigit(char C)
{
	if(C >= '0' && C <= '9') return true;
	return false;
}

// temdegt uildel ni operator iin temdeg esehiig shalgah
bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}

// 2 operandiin uildliig guiitsetgen ur dung butsah
int PerformOperation(char operation, int operand1, int operand2)
{
	if(operation == '+') return operand1 +operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;

	else cout<<"Unexpected Error \n";
	return -1;
}

