#include <iostream>
#include <string.h>
#include <iomanip>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

string medicine_info_name(char medCode);
char medicine_code();														
void check(char methode);
void appointment();
void display_medicine_info();
void medicine_info_price(char medCode,double& medPrice);


int main()
{
	int qtty[20], num, stockA=20, stockB=20, stockC=20, stockD=20, stockE=20, stockF=20, countCust=0;
	char start, ans, medCode[20], payMethod;
	double medPrice[20], pricePerMed[20], discount, income=0;
	string userID, userName, medName[20], maxName, illness, phoneNumber, date, pay;
	const string sick_name[6]={"Headache","Fever","Common Cold","Cought","Diarrhea","Sore Throat"};
	
	
//	FIRST QUESTION FOR USER BEFORE ENTER THE SYSTEM	
	cout << "Hello there, do you want to buy a medicine? (y/n) : " ;
	cin >> start;
	start=tolower(start);
	cin.ignore(100,'\n');
	
//	OUTER LOOP (MAIN)
	while(start != 'n')
	{
//		THE DECLARATION BELOW IS USE TO RESET THE VALUE EVERYTIME AFTER NEW USER ENTER THE SYSTEM
		bool exit=false, printHighest=true, checkStock=true;
		int a=0, maxQtty=0, countMedicine=0;
		double totalMedPrice=0, disPrice=0, totalPerUser=0;
	
//		PROMPT USER TO INPUT THEIR MATRICS NUMBER	
		cout << "\nEnter your matrics number : ";
		cin >> userID;
		
//		LOOPING EXECUTE IF USER ENTER INCORRECT INPUT		
		while(userID.length() != 10)
		{
			cin.clear();
			cin.ignore(100,'\n');
			cout << "Wrong Student ID (must be 10 digits)" << endl;
			cout << "\nEnter your matrics number : ";
			cin >> userID;
		}
		
//		PROMPT USER TO INPUT THEIR NAME			
		cin.clear();	
		cin.ignore();
		cout << "Please enter your name    : ";
		getline(cin,userName);
		
		system("cls");
		cout << "Hello, " << userName << " ^-^" << endl;
		
//		CALL FUNCTION TO DISPLAY THE MEDICINE CHOICE
		display_medicine_info();
		
		
//		REPETITION TO ASK, READ INPUT AND CHECK MEDICINE INFORMATION AS USER WANT
		do
		{
			do
			{
				ans='y';
				checkStock=true;
				pricePerMed[a]=0;
				
//				PROMPT USER TO ENTER MEDICINE CODE THEY WISH TO BUY					
				cout << "\n" << a+1 << ". Enter medicine you need            : ";
				
//				CALL FUNCTION TO GET MEDICINE CODE FROM USER
				medCode[a]=medicine_code();
				
//				CALL FUNCTION TO RETURN MEDICINE NAME AND PRICE BASED ON THE CODE ABOVE				
				medName[a]=medicine_info_name(medCode[a]);
				medicine_info_price(medCode[a],medPrice[a]);
				
				
//				IF STATEMENT FOR INVALID INPUT (MEDICINE CODE)				
				if(medName[a]=="invalid")
				{
					cout << "   INVALID CODE press 'c' to continue : ";
					cin >> ans;	
					ans=tolower(ans);
					cin.ignore(100,'\n');
						
					if(ans != 'c')
					{
						cout << "   Please CONFIRM to exit ? (y/n)     : ";
						cin >> ans;	
						ans=tolower(ans);
						cin.ignore(100,'\n');
						
						if(ans!='n')
						{
							cout<< "\n\n________________ THANK YOU FOR USING OUR SERVICE ________________";	
							cout << a << "  " << countMedicine << endl;	
							exit=true;
							goto out;
						}
					}
				}
			}
			while(ans=='c' || ans=='n');
			
//			ASK USER FOR THE QUANTITY OF THE MEDICINE 			
			cout << "   How much do you want ?             : ";
			cin >> qtty[a];

//			IF USER INPUT CHARACTER OR STRING THIS LOOPING WILL EXECUTE UNTIL USER INPUT INTEGER				
			while(!qtty[a])
			{
				cin.clear();
				cin.ignore(100,'\n');
				cout << "   How much do you want ?             : ";
				cin >> qtty[a];
			}
			
//			THIS SWITCH WORKS TO CHECK IF THE STOCK IS AVAILABLE FOR EACH MEDICINE			
			switch(medCode[a])
			{
			case 'a':
				stockA=stockA-qtty[a];
				if(stockA<0)
				{
					checkStock=false;
					stockA=stockA+qtty[a];
					cout << "\n   Stock available : " << stockA << endl;
				} 
				break;
				
			case 'b':
				stockB=stockB-qtty[a];
				if(stockB<0)
				{
					checkStock=false;
					stockB=stockB+qtty[a];
					cout << "\n   Stock available : " << stockB << endl;
				}
				break;
			
			case 'c':
				stockC=stockC-qtty[a];
				if(stockC<0)
				{
					checkStock=false;
					stockC=stockC+qtty[a];
					cout << "\n   Stock available : " << stockC << endl;
				}
				break;
				
			case 'd':
				stockD=stockD-qtty[a];
				if(stockD<0)
				{
					checkStock=false;
					stockD=stockD+qtty[a];
					cout << "\n   Stock available : " << stockD << endl;
				}break;
				
			case 'e':
				stockE=stockE-qtty[a];
				if(stockE<0)
				{
					checkStock=false;
					stockE=stockE+qtty[a];
					cout << "\n   Stock available : " << stockE << endl;
				}break;
				
			case 'f':
				stockF=stockF-qtty[a];
				if(stockF<0)
				{
					checkStock=false;
					stockF=stockF+qtty[a];
					cout << "\n   Stock available : " << stockF << endl;
				}break;					
			}
			
//			ADDITIONAL STATEMENT FOR SWITCH ABOVE
			if(checkStock==0) 
			{
				cout << "   You have reached the maximum quantity available for this item :(" << endl;
				cout << "   Please order again the medicine based on the available stock  " << endl;
				
				cin.clear();
				cin.ignore(100,'\n');
				qtty[a]=0;
			}
			
			
//			CHECK THE MAXIMUM QUANTITY OF MEDICINES THAT USER INPUT			
			if(qtty[a]>maxQtty)
			{
				maxQtty=qtty[a];
				maxName=medName[a];
				
				if(medCode[a]=='a') 
					illness=sick_name[0];
				else if(medCode[a]=='b') 
					illness=sick_name[1];
				else if(medCode[a]=='c') 
					illness=sick_name[2];
				else if(medCode[a]=='d') 
					illness=sick_name[3];
				else if(medCode[a]=='e') 
					illness=sick_name[4];
				else if(medCode[a]=='f') 
					illness=sick_name[5];
			}
//			IF THERE IS TWO HIGHEST MEDICINE, THE CONDITION AT LINE 400 WILL BE FALSE
			else if(qtty[a]==maxQtty)
			{
				printHighest=false;
			}
			
//			THIS IF STATEMENT NECESSARY TO CHECK THE CONDITION AT LINE 235
			if(checkStock==0) a--;
			
//			ASK USER WHETHER THEY WANT TO ADD ANOTHER MEDICINE			
			cout << "\n   Anything to add ? (y/n)            : ";
			cin >> ans;
			ans=tolower(ans);
			cin.ignore(100,'\n');
			
//			IF USER DON'T WANT TO ADD ANOTHER MEDICINE, AND HAVE NOTHING IN THEIR ORDER LIST, THE SYSTEM WILL EXIT BY SKIP TO CERTAIN LINE			
			if(ans!='y' && a<0)
			{
				cout << "\n\n                    NOTHING IN YOUR ORDER LIST                   " << endl;
				cout<< " ________________ THANK YOU FOR USING OUR SERVICE ________________" << endl;
				goto out;
			}
			
//			IF USER DON'T WANT TO ADD ANOTHER MEDICINE, SYSTEM WILL ASK TO CONTINUE FOR THE PAYMENT METHOD				
			else if(ans!='y')
			{
				cout << "   Continue to payment method ? (y/n) : ";
				cin >> ans;
				ans=tolower(ans);
				cin.ignore(100,'\n');
				
				if(ans!='y')
				{
					cout << "   Exit or Continue ?           (e/c) : ";
					cin >> ans;
					ans=tolower(ans);
					cin.ignore(100,'\n');
					
					if(ans=='e') 
					{
						cout<< "\n\n________________ THANK YOU FOR USING OUR SERVICE ________________";
						countMedicine++;
						a++;
						exit=true;
						goto out;
					}
					else ans='y';	
				}
//				THIS ELSE STATEMENT NECESSARY TO GET OUT FROM THE LOOP CONDITION AT LINE 278
				else ans='a';
			}
			
//			CERTAIN CALCULATION AND UPDATE WON'T BE EXECUTE IF THE MEDICINE IS OUT OF STOCKS (BASED ON SWITCH AT LINE 128)
			if(checkStock==1) 
			{
				pricePerMed[a]=medPrice[a]*qtty[a];
				totalMedPrice=totalMedPrice+pricePerMed[a];
				countMedicine++;
			}
			a++;	
		}
		while( ans =='y' );
		
		
//		PROMPT USER TO CHOOSE PAYMENT METHOD		
		system("cls");
		cout << "\n [A] QR PAY      -  5% discount ";
		cout << "\n [B] DEBIT CARD  -  0% discount ";
		cout << "\n\n Please select the payment methods : ";
		
		cin >> payMethod;
		payMethod=tolower(payMethod);
		cin.ignore(100,'\n');
		
//		LOOPING EXECUTE IF USER ENTER INVALID INPUT OPTION		
		while (payMethod!='a' && payMethod!='b')
		{
			cout << " Please select the payment methods : ";
			cin >> payMethod;
			
			cin.ignore(100,'\n');
			payMethod=tolower(payMethod);
		}
		
//		DECLARE SOME INFORMATION BASED ON THE INPUT FROM PAYMENT METHOD		
		switch(payMethod) 
		{
		case 'a':
			discount=0.05;
			pay="QR PAY";
			break;
		
		case 'b':
			discount=0.00;
			pay="DEBIT CARD";
			break;
		} 
		
//		CALCULATION FOR DISCOUNT PRICE AND TOTAL PRICE FOR CURRENT USER		
		disPrice=totalMedPrice*discount;
		totalPerUser=totalMedPrice-disPrice;
		
//		PRINT ORDER SUMMARY FOR USER CONFIRMATION		
		system("cls");
		cout << "\n";
		cout<<fixed<<setprecision(2)<<showpoint;
		cout << " ----------- YOUR ORDER'S SUMMARY ----------  \n" << endl;
		
//		LOOPING STATEMENT USED TO DISPLAY DATA FROM USER THAT STORED IN ARRAY		
		for( a=0; a<countMedicine; a++)
		{
			cout << "\t" << a+1 << ". " << medName[a] << "  \tx " << qtty[a] << endl;
		}
			
		cout << "\n ------------------------------------------- " << endl;
		cout << "            TOTAL   =   RM" << totalPerUser << endl;
		cout << " -------------------------------------------  " << endl;
	
//		RECONFIRM THE USER WHETHER USER WANT TO PROCEED THE PAYMENT OR EXIT THE SYSTEM			
		do
		{
			cout << " Do you want to proceed with the payment ? (y/n) : " ;
			cin >> ans;	
			
			cin.ignore(100,'\n');
			ans=tolower(ans);
		}
		while(ans!='y' && ans!='n');
		
		if(ans=='n')
		{
			cout << " Please confirm to exit ? (y/n) : ";	
			cin >> ans;
			
			cin.ignore(100,'\n');
			ans=tolower(ans);
			
			if(ans!='n' && ans!='N')
			{
				cout<< "\n\n________________ THANK YOU FOR USING OUR SERVICE ________________";	
				exit=true;
				goto out;
			}
		}
		
//		COUNT NUMBER OF USER THAT PROCEED TO BUY THE MEDICINE AND CALCULATE TOTAL INCOME FOR ADMIN REPORT
		countCust++;
		income=income+totalPerUser;
		
//		CALL FUNCTION TO DISPLAY THE INSTRUCTION FOR USER TO MAKE A PAYMENT	
		check(payMethod);
		
//		PRINT OUT THE OFFICIAL RECEIPT FROM THE MACHINE	AFTER SUCCESSFUL PAYMENT	
		system("cls");
		cout << " xxxxxxxxxxxxxxxxxxx  OFFICIAL RECEIPT  xxxxxxxxxxxxxxxxxxx " << endl;
		cout << "                                                            " << endl;
		cout << " -------------- PENAWAR SELF-SERVICE MACHINE -------------- " << endl;
		cout << "                                                            " << endl;
		cout << "  NAME  : " << userName << endl;
		cout << "  ID    : " << userID <<endl;
		cout << "                                                            " << endl;
		cout << " ---------------------------------------------------------- " << endl;
		
//		LOOPING STATEMENT USED TO DISPLAY DATA FROM USER THAT STORED IN ARRAY		
		cout<<fixed<<setprecision(2)<<showpoint;
		for( a=0; a<countMedicine; a++)
		{
			cout << "\t" << a+1 << ". " << medName[a] << "  \t " << medPrice[a] << " x " << qtty[a] << "   = RM" << pricePerMed[a] << endl;
		}
			
		cout << " ---------------------------------------------------------- " << endl;
		cout << "                                                            " << endl;	
		cout << "         PAYMENT METHOD   :\t " << pay << endl;
		cout << "         MEDICINE PRICE   :\t RM " << totalMedPrice << endl;
		cout << "         DISCOUNT         :\t RM " << disPrice << endl;
		cout << "                                                            " << endl;
		cout << "         TOTAL            =\t RM " << totalPerUser << endl;
		cout << "                                                            " << endl;
		cout << "  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ " << endl;
		cout << "              THANK YOU FOR USING OUR SERVICE               " << endl;
		cout << "  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ " << endl;
		
//		PRINT THE HIGHEST MEDICINE QUANTITY AND THE INFORMATION BELOW IF MEET THE CONDITION		
		if(printHighest==1)
		{
			cout << "\n\t Highest medicine quantity : " << maxQtty  << endl;
			cout << "\t Medicine name     : " << maxName << endl;
			cout << "\t Possible illness  : " << illness << endl;
			cout << "  --------------------------------------------------------- " << endl;
		}
				
		cout << "\n  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx " << endl;
		
				
//		ADVISE USER TO MAKE AN APPOINTMENT WITH DOCTOR IF THEY BUY MORE THAN THREE TYPE OF MEDICINE
//		THIS CONDITION WILL ASK USER TO INPUT THE DETAILS TO MAKE AN APPOINTMENT		
		if (countMedicine>3)
		{
			cout << "\n Seems like you are having a serious illness, We recommend you to meet our doctor " << endl;
			cout << " Do you want to make an appointment ? (y/n) : ";
			cin >> ans;       
			  
			ans=tolower(ans);
			cin.ignore(100,'\n');
			
//			IF THE USER AGREE MAKE AN APPOINTMENT, FUNCTION appointment() WILL BE CALL
			if(ans=='y')
			{
				system("cls");
				appointment();
			}
		}
		
	out:
//		THIS CONDITION WILL ADDING BACK EACH QUANTITY FOR EVERY MEDICINE THAT HAS BEEN CANCELLED	
		if(exit==1)
		{
			for(a=0; a<countMedicine; a++)
			{
				if(medCode[a]=='a') 
					stockA=stockA+qtty[a];
				else if(medCode[a]=='b') 
					stockB=stockB+qtty[a];
				else if(medCode[a]=='c') 
					stockC=stockC+qtty[a];
				else if(medCode[a]=='d') 
					stockD=stockD+qtty[a];
				else if(medCode[a]=='e') 
					stockE=stockE+qtty[a];
				else if(medCode[a]=='f') 
					stockF=stockF+qtty[a];
			}
			
		}
		
//		TEN SECONDS AFTER RECEIPT PRINTED, SYSTEM WILL BE BACK TO THE MAIN PAGE			
		cout << "\n\n System will be clear in 10 seconds ";
		sleep(10);

//		PROMPT NEXT USER TO ENTER THE SYSTEM		
		system("cls");
		cout << "Hello there, do you want to buy a medicine? (y/n) : " ;
		cin >> start;
		
		cin.ignore(100,'\n');
		start=tolower(start);
	}

//	ONLY ADMIN CAN ENTER 'N' FOR QUESTION AT LINE 457 AND SEE THE REPORT
	cout << "\n REPORT SUMMARY               "    << endl;
	cout << " ------------------------------ "    << endl;
	cout << "   MEDICINE            STOCK    "    << endl;
	cout << " ------------------------------ "    << endl;
	cout << "   Paracetamol       - \t" << stockA << endl;
	cout << "   Acetaminophen     - \t" << stockB << endl;
	cout << "   Loratadine        - \t" << stockC << endl;
	cout << "   Cloperastine HCL  - \t" << stockD << endl;
	cout << "   Loparamide HCL    - \t" << stockE << endl;
	cout << "   Difflam lozenge   - \t" << stockF << endl;
	cout << " ------------------------------ "    << endl;
	cout << "   TOTAL INCOME    = RM"   << income << endl;
	cout << " ------------------------------ "    << endl;
	cout << "   TOTAL CUSTOMER  = "  << countCust << endl;
	cout << " ------------------------------ "    << endl;

	return 0;
}	
//-------------------------------------------- END OF MAIN FUNCTION --------------------------------------------------------//


//	FUNCTION TO DISPLAY OPTION DIAGRAM BELOW
void display_medicine_info()
{
	cout << "\n -------------- WELCOME TO PENAWAR SELF-SERVICE MEDICINES MACHINE ---------------- " << endl;  
	cout << "                                                                                   " << endl;
	cout << "   * 1 strip = 2 tablets                                                           " << endl;
	cout << "   * Based on professional advices                                                 " << endl;
	cout << "   ____________________________________________________________________________    " << endl;
	cout << "  | TYPE OF ILLNESSES |  RECOMMENDED MEDICINES   | DOSES PER | PRICE PER STRIP |   " << endl;  
	cout << "  |___________________|__________________________|___TABLET__|_________________|   " << endl; 
	cout << "  |                   |                          |           |                 |   " << endl;
	cout << "  |   Headache        |   [A] Paracetamol        |   500mg   |     RM 0.20     |   " << endl; 
	cout << "  |   Fever           |   [B] Acetaminophen      |   250mg   |     RM 0.40     |   " << endl; 
	cout << "  |   Common cold     |   [C] Loratadine         |   10mg    |     RM 0.50     |   " << endl; 
	cout << "  |   Cough           |   [D] Cloperastine HCL   |   10mg    |     RM 0.80     |   " << endl; 
	cout << "  |   Diarrhea        |   [E] Loparamide HCL     |   2mg     |     RM 1.80     |   " << endl;
	cout << "  |   Sore Throat     |   [F] Difflam lozenge    |   12mg    |     RM 1.20     |   " << endl;	
	cout << "  |___________________|__________________________|___________|_________________|   " << endl;
	cout << "                                                                                   " << endl;
	cout << " * Unavailable items will be excluded from your bill                               " << endl;
	cout << " --------------------------------------------------------------------------------- " << endl;
	cout << " Only enter the medicine code from the table above for the next question         \n" << endl;
}

//	FUNCTION TO PROMPT AND RETURN INPUT
char medicine_code()
{
	char code;
	
	cin >> code;
	code=tolower(code);
	cin.ignore(100,'\n');
	
	return code;
}

//	FUNCTION THAT RECEIVE MEDICINE CODE AND RETURN MEDICINE NAME
string medicine_info_name(char medCode)
{
	string medName;
	
	if(medCode=='a') 
		medName="Paracetamol     ";
	else if(medCode=='b') 
		medName="Acetaminophen   ";
	else if(medCode=='c') 
		medName="Loratadine      ";
	else if(medCode=='d') 
		medName="Cloperastine HCL";
	else if(medCode=='e') 
		medName="Loparamide HCL  ";
	else if(medCode=='f') 
		medName="Difflam lozenge ";
	else 
		medName="invalid";
	
	return medName;
}

//	FUNCTION THAT RECEIVE MEDICINE CODE AND RETURN MEDICINE PRICE BY REFERENCE
void medicine_info_price(char medCode,double& medPrice)
{
	if(medCode=='a') 
		medPrice=0.2;
	else if(medCode=='b') 
		medPrice=0.4;
	else if(medCode=='c') 
		medPrice=0.5;
	else if(medCode=='d') 
		medPrice=0.8;
	else if(medCode=='e') 
		medPrice=1.8;
	else if(medCode=='f') 
		medPrice=1.2;
	else 
	medPrice=0.00;
}

//	FUNCTION THAT RECEIVE CHARACTER AND DISPLAY INSTRUCTION
void check(char methode)
{
	char ans;
	switch(methode)
	{
	case 'a':	
		cout << "\n Please scan this code......" << endl;
		cout << "   ________________________   " << endl;
		cout << "  |  ____  ||__|  |  ____  |  " << endl;
		cout << "  | |    | | _    | |    | |  " << endl;
		cout << "  | |____| || |   | |____| |  " << endl;
		cout << "  |________|| |_  |________|  " << endl;
		cout << "  |  _  _   |___|   ______ |  " << endl;
		cout << "  | |_||_|   ____  |   ___||  " << endl;
		cout << "  |________ |  __| |__|    |  " << endl;
		cout << "  |  ____  || | _   __   _ |  " << endl;
		cout << "  | |    | || || |_|  |_| ||  " << endl;
		cout << "  | |____| ||_||__________||  " << endl;
		cout << "  |________|_______________|  " << endl;
		cout << "                              " << endl;
		cout << "Done scanning, ";
		system("pause");
		break;

	case 'b': 
		cout << "\n Please wave the card at the terminals " << endl;
		cout << " Processing, ";
		system("pause");
		break;
	} 
}

//	FUNCTION TO PROMPT AND DISPLAY INPUT FROM USER 
void appointment()
{
	string userID, userName, phoneNumber, date;
	
	cout << "PLEASE ANSWER QUESTION BELOW CORRECTLY \n\n";
		
	cout << "Enter your matrics number : ";
	cin >> userID ;
	
	while(userID.length() != 10)
	{
		cout << "Wrong Student ID (must be 10 digits)" << endl;
		cout << "\nEnter your matrics number : ";
		cin >> userID;
	}
	
	cin.ignore();
	cout << "Enter your full name      : ";
	getline(cin,userName);
	
	cout << "Enter your phone number   : ";
	getline(cin,phoneNumber);
	
	cout << "\nDate format dd/mm " << endl;
	cout << "Enter appointment date    : ";
	cin >> date;
	
	cout << "\n\n";
	cout << " --------------------------------------------------------- " << endl;
	cout << "              Here's your appointment details              " << endl;
	cout << " --------------------------------------------------------- " << endl;
	cout << "                                                           " << endl;
	cout << "  ID           : " << userID << endl;
	cout << "  Name         : " << userName << endl;
	cout << "  Phone number : " << phoneNumber << endl;
	cout << "  Date         : " << date << "/2023" << endl;
	cout << "  Location     : Klinik Penawar,UiTM Segamat " << endl;
	cout << "                                                           " << endl;
	cout << "  OUR CLINIC WILL CALL YOU SHORTLY TO RECONFIRM ^-^        " << endl;
	cout << " --------------------------------------------------------- " << endl;
}
