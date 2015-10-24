#include "list.h"


/*    BRIEF: Добавление элементов в начало списка

         IN:   val - значение

               begin - указатель на начало списка

               end - указатель на конец списка
                     (на случай, если список был пуст)	
*/

void addBegin(int val, node_list *&begin, node_list *&end)
{
	node_list *var = new node_list;
	
	var->val = val;
	var->next = begin;
	
	begin = var;
	
	if (!end) 
	{
		end = begin;             //  В случае, когда список был пуст,
    }                            //  значение end должно быть изменено
}

/*    BRIEF: Добавление элементов в конец списка

         IN:    val - значение

              begin - указатель на начало списка
                      (на случай, если список был пуст)

                end - указатель на конец списка
*/

void addEnd(int val, node_list *&begin, node_list *&end)
{
	node_list *var = new node_list;
	
	var->val = val;
	var->next = NULL;
	
    if (end) 
	{
		end->next = var;           
	}
    else 
	{									//  В случае, когда список был пуст,
			begin = var;                //  значение begin должно быть изменено
	}
    
	end = var;
}

/*	BRIEF: Добавить после элемента с заданным значением

	   IN: val - значение нового элемента
	   
	   		 n - значение элемента, после которого 
			   	 будет добавлен новый элемент
			 
			   	 
	  OUT:   1 - список пуст или заданное значение val в нем отсутствует
		 	
*/

int addAfter(int val, int n, node_list *begin, node_list *&end)
{
	if (!begin)
	{
		return 1;
	}
	
	while (begin->val != n)	         //  найдем адрес элемента 
	{                                //  с заданным значением n
		begin = begin->next;         //  либо адрес будет в begin,
		     
		if (!begin) 
		{
			return 1;                //  либо фукция вернет 1
		}				             
	}                                
	
	node_list *temp = new node_list;
	
	temp->val = val;
	temp->next = begin->next;
	
	begin->next = temp;
	                                  
									  
	if (begin == end)                 //  если новый элемент был добавлен
	{                                 //  после последнего, то значение
		end = temp;                   //  end должно быть изменено на адрес 
	}                                 //  нового элемента
	                                  
	return 0;
}

/*	BRIEF: BRIEF: Добавить перед элементом с заданным значением

	   IN: val - значение нового элемента
	   
	   		 n - значение элемента, перед которым
			   	 будет добавлен новый элемент
			 
			   	 
	  OUT:   1 - список пуст или заданное значение val в нем отсутствует
		 	
*/

int addBefore(int val, int n, node_list *&begin, node_list *end)
{
	if (!begin)
	{
		return 1;
	}
	
	if (begin->val == n)                   //  если элемент со значением n
	{                                      //  есть первый элемент в списке,
		node_list *temp = new node_list;
		
		temp->val = val;
		temp->next = begin;                
		                                   //  теперь первым будет элемент 
		begin = temp;                      //  с адресом temp
		
		return 0;
	}
	else
	{
		
		if (!begin->next)
		{
			return 1;
		}
		
		node_list *buf = begin;	            

		while ((buf->next)->val != n)	   //  найдем адрес элемента, 
		{                                  //  за которым следует элемент
			buf = buf->next;               //  со значением n
			if (!buf->next)                //  либо адрес будет в buf,
			{                              
				return 1;	               //  либо функция вернет 1
			} 
		}                                  
		                                   
		node_list *temp = new node_list;
		
		temp->val = val;
		temp->next = buf->next;
		
		buf->next = temp;
		
		return 0;
	}	
}

/*	BRIEF: Удалить элемент с заданным значением

	   IN:	n - значение элемента, который
		    	будет удален			 
			   	 
	  OUT:  1 - список пуст или заданное значение val в нем отсутствует
		 	
*/

int erase(int n, node_list *&begin, node_list *&end)
{
	if (!begin)
	{
		return 1;
	}
	
	if (begin->val == n)                   //  если элемент со значением n
	{                                      //  есть первый элемент в списке,
		node_list *temp = begin->next;	
		
		delete (begin);
		
		begin = temp;
		
		if (!begin)
		{
			end = begin;
		}
		
		return 0;
	}
	else
	{
		
		if (!begin->next)
		{
			return 1;
		}
		
		node_list *buf = begin;	            
		
		while ((buf->next)->val != n)	   //  найдем адрес элемента, 
		{                                  //  за которым следует элемент
			buf = buf->next;               //  со значением n
			if (!buf->next)                //  либо адрес будет в buf,
			{
				return 1;	               //  либо функция вернет 1
			}
			
		}                                  
		                                   
		node_list *temp = buf->next;
		
		buf->next = temp->next;
		
		delete (temp);
		
		if (!buf->next) 
		{
			end = buf;                     //  если удалили последний..
		}
		
		return 0;
	}	
}

/*	BRIEF: Сортировка

	  OUT:  1 - список пуст
*/

int sorting(node_list *&begin, node_list *&end)
{
	if (!begin)                                   //  если список пуст
	{
		return 1;
	}

	if (!(begin->next))                           //  если в списке
	{                                             //  всего один элемент
		return 1;
	}

	node_list *end_assist = NULL;


	while (begin->next != end_assist)
	{
		if (begin->val > begin->next->val)
		{
			node_list *temp = begin->next;

			begin->next = temp->next;
			temp->next = begin;

			if (!(begin->next))                       //  на случай, если в списке
			{                                         //  всего два элемента
				end = begin;
				begin = temp;
				return 0;
			}

			begin = temp;
		}

		node_list *current = begin;

		while (current->next->next != end_assist)
		{
			if (current->next->val > current->next->next->val)
			{
				node_list *temp1 = current->next, *temp2 = temp1->next;

				temp1->next = temp2->next;
				temp2->next = temp1;
				current->next = temp2;

				if (!(temp1->next))
				{
					end = temp1;
				}
			}
			current = current->next;
		}
		end_assist = current->next;
	}
	return 0;
}

/* print, просто print.. */

void print(node_list *begin)
{
	if (!begin) 
	{
		cout << "<Cписок пуст>";
	}
	
	while (begin)
    {
	    cout << (*begin).val << " ";
	    begin = (*begin).next;
    }
    
	cout << endl << endl;
}

/*	BRIEF: Меню

	  OUT: 0 - когда был выбрал пункт выход
*/

int menuList()
{
	setlocale(LC_ALL, "Rus");

	node_list *begin = NULL;
	node_list *end = NULL;

	int m;
	while (1)
	{
		system("CLS");
		cout << "Работа со списком:\t\t\t";
		cout << endl << endl << endl;
		cout << "1. Добавить в начало." << endl << endl;
		cout << "2. Добавить в конец." << endl << endl;
		cout << "3. Добавить после элемента равного n." << endl << endl;
		cout << "4. Добавить перед элементом равным n." << endl << endl;
		cout << "5. Удалить элемент равный n." << endl << endl;
		cout << "6. Сортировка." << endl << endl;
		cout << "7. Вывести список." << endl << endl;
		cout << "0. Выход." << endl << endl;


		cout << "Выберете пункт меню: ";
		while (scanIntVal(m) || (m < 0) || (m > 7))
		{
			cout << "\nОшибка. Попробуйте еще раз.\n\nВыберете пункт меню: ";
		}
		cout << endl;

		switch (m)
		{
		case 1:
		{
			int a;
			while (1)
			{
				cout << "Введите значение: ";
				if (scanIntVal(a))
				{
					cout << "\nОшибка. Попробовать еще раз? (Y/N) -->";
					if (scanYesNo())
					{
						continue;
					}
					else
					{
						break;
					}
				}
				addBegin(a, begin, end);
				cout << "Добавить еще значение? (Y/N) -->";
				if (!scanYesNo())
				{
					break;
				}
			}
			break;
		}
		case 2:
		{
			int a;
			while (1)
			{
				cout << "Введите значение: ";
				if (scanIntVal(a))
				{
					cout << "\nОшибка. Попробовать еще раз? (Y/N) -->";
					if (scanYesNo())
					{
						continue;
					}
					else
					{
						break;
					}
				}
				addEnd(a, begin, end);
				cout << "Добавить еще значение? (Y/N) -->";
				if (!scanYesNo())
				{
					break;
				}
			}
			break;
		}
		case 3:
		{
			int n, val;

			while (1)
			{
				cout << "Введите значение, которое нужно добавить: ";
				if (scanIntVal(val))
				{
					cout << "\nОшибка. Попробовать еще раз? (Y/N) -->";
					if (scanYesNo())
					{
						continue;
					}
					else
					{
						break;
					}
				}

				cout << "Введите значение, после которого добавить: ";
				if (scanIntVal(n))
				{
					cout << "\nОшибка. Попробовать еще раз? (Y/N) -->";
					if (scanYesNo())
					{
						continue;
					}
					else
					{
						break;
					}
				}

				if (addAfter(val, n, begin, end))
				{
					cout << endl << endl << "Список пуст или такого элемента в нем нет." << endl << endl;
					cout << "1. Добавить в начало." << endl << endl;
					cout << "2. Добавить в конец." << endl << endl;
					cout << "3. Попробовать еще раз." << endl << endl;
					cout << "0. Ничего не делать." << endl << endl;
					cout << "Выберете пункт меню: ";
					int q;
					while (scanIntVal(q) || (q < 0) || (q > 3))
					{
						cout << "\nОшибка. Попробуйте еще раз.\n\nВыберете пункт меню: ";
					}
					cout << endl;
					switch (q)
					{
					case 1:
					{
						addBegin(val, begin, end);
						break;
					}
					case 2:
					{
						addEnd(val, begin, end);
						break;
					}
					case 3:
					{
						continue;
						break;
					}
					default:
					{

					}
					}
					break;
				}
				else
				{
					break;
				}
			}
			break;
		}
		case 4:
		{
			int n, val;

			while (1)
			{
				cout << "Введите значение, которое нужно добавить: ";
				if (scanIntVal(val))
				{
					cout << "\nОшибка. Попробовать еще раз? (Y/N) -->";
					if (scanYesNo())
					{
						continue;
					}
					else
					{
						break;
					}
				}

				cout << "Введите значение, перед которым добавить: ";
				if (scanIntVal(n))
				{
					cout << "\nОшибка. Попробовать еще раз? (Y/N) -->";
					if (scanYesNo())
					{
						continue;
					}
					else
					{
						break;
					}
				}

				if (addBefore(val, n, begin, end))
				{
					cout << endl << endl << "Список пуст или такого элемента в нем нет." << endl << endl;
					cout << "1. Добавить в начало." << endl << endl;
					cout << "2. Добавить в конец." << endl << endl;
					cout << "3. Попробовать еще раз." << endl << endl;
					cout << "0. Ничего не делать." << endl << endl;
					cout << "Выберете пункт меню: ";
					int q;
					while (scanIntVal(q) || (q < 0) || (q > 3))
					{
						cout << "\nОшибка. Попробуйте еще раз.\n\nВыберете пункт меню: ";
					}
					cout << endl;
					switch (q)
					{
					case 1:
					{
						addBegin(val, begin, end);
						break;
					}
					case 2:
					{
						addEnd(val, begin, end);
						break;
					}
					case 3:
					{
						continue;
						break;
					}
					default:
					{

					}
					}
					break;
				}
				else
				{
					break;
				}
			}
			break;
		}
		case 5:
		{
			if (!begin)
			{
				print(begin);
				system("PAUSE");
				break;
			}

			int a;
			while (1)
			{
				cout << "Введите значение, которое нужно удалить: ";
				if (scanIntVal(a))
				{
					cout << "\nОшибка. Попробовать еще раз? (Y/N) -->";
					if (scanYesNo())
					{
						continue;
					}
					else
					{
						break;
					}
				}
				if (erase(a, begin, end))
				{
					cout << "Такого значение в списке нет. Попробовать еще раз? (Y/N) -->";
					if (scanYesNo())
					{
						continue;
					}
					else
					{
						break;
					}
				}
				cout << "Элемент со значением " << a << " удален." << endl << endl;
				cout << "Удалить еще? (Y/N) -->";
				if (!scanYesNo())
				{
					break;
				}
			}
			break;
		}
		case 6:
		{
			if (!sorting(begin, end))
			{
				cout << "Отсортированный список:" << endl << endl;
				print(begin);
			}
			else
			{
				cout << "Ошибка!! Добавьте больше элементов." << endl << endl;
			}

			system("PAUSE");
			break;
		}
		case 7:
		{
			print(begin);
			system("PAUSE");
			break;
		}
		default:
		{
			while (begin)
			{
				node_list *temp = (*begin).next;
				delete begin;
				begin = temp;
			}
			return 0;
		}
		}
	}
}
