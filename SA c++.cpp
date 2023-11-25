#include <iostream>
#include <locale.h>
#include <string.h>

using namespace std;

int op1, op2, op3, linha;
string tipo;

struct info{
	
	string nome, cpf, telefone, email, nasc, marca, site, cnpj, prod;
	int disp, vend;
	double preco;
};

info banco[5][1000];

//linha 0: hardwares
//linha 1: periféricos
//linha 2: clientes
//linha 3: fonecedores
//linha 4: parceiros


//todos os do while são usados para verificar se a opção escolhida é válida

//menu principal
void menu_principal(){
	
	system("cls");
	
	do{
		cout << "MENU PRINCIPAL \n \n";
		cout << "1. Produtos \n";
		cout << "2. Clientes \n";
		cout << "3. Fornecedores \n";
		cout << "4. Parceiros \n";
		cout << "5. Ajuda \n";
		cout << "6. Sobre \n";
		cout << "7. Logoff";
		cout << "\nQual opção deseja acessar? \n=> ";
		cin >> op1;
		cin.sync();
		
		system("cls");
	
	}while(op1 > 7 or op1 < 1);	
}

//sub menu
void subMenu(){
	
	//system("cls");
	
	do{
		cout << "1. Listar todos \n";
		cout << "2. Pesquisar \n";
		cout << "3. Cadastrar novo \n";
		cout << "4. Atualizar \n";
		cout << "5. Excluir \n";
		cout << "6. Retornar \n";
		cout << "\nQual opção deseja acessar? \n=> ";
		cin >> op2;
		cin.sync();
		
		system("cls");
	
	}while(op2 > 6 or op2 < 1);	
}


//ficha genérica pra qualquer informação
int ficha(int lin, int col){
	
	cout << "\n==============> Dados "<< tipo <<" <==============\n";
	
	cout << "\nCódigo: " << col;
	cout << "\n1. Nome: " << banco[lin][col].nome;
	
	if(lin == 0 or lin == 1){  //dados dos produtos
		
		cout << "\n2. Marca: " << banco[lin][col].marca;
		cout << "\n3. Preço: R$ " << banco[lin][col].preco;
		cout << "\n4. Site: " << banco[lin][col].site;
		cout << "\n5. Vendidos: " << banco[lin][col].vend;
		cout << "\n6. Disponível: " << banco[lin][col].disp;
	
	}else if(lin == 2){  //dados dos clientes
	
		cout << "\n2. CPF: " << banco[lin][col].cpf;
		cout << "\n3. E-mail: " << banco[lin][col].email;
		cout << "\n4. Telefone: " << banco[lin][col].telefone;
		cout << "\n5. Data de nascimento: " << banco[lin][col].nasc;
		
	}else if(lin == 3){  //dados dos fornecedores
		
		cout << "\n2. CNPJ: " << banco[lin][col].cnpj;
		cout << "\n3. E-mail: " << banco[lin][col].email;
		cout << "\n4. Telefone: " << banco[lin][col].telefone;
		cout << "\n5. Produtos fornecidos: " << banco[lin][col].prod;
		
	}else if(lin == 4){  //dados dos parceiros
		
		cout << "\n2. CNPJ: " << banco[lin][col].cnpj;
		cout << "\n3. E-mail: " << banco[lin][col].email;
		cout << "\n4. Telefone: " << banco[lin][col].telefone;
		//cout << "\nProdutos anunciados: ";
	}

	cout << "\n\n=============================================\n";
}



//listar
int listar(int lin){
	
	for(int col = 0; col < 1000; col++){
		
		if(banco[lin][col].nome != " "){
			
			ficha(lin, col);
		}
	}
	do{
		cout << "\n1. Voltar \n2. Menu principal \n=> ";
		cin >> op3;
	
	}while(op3 != 1 and op3 != 2 );
	
	switch(op3){
		
		case 2:
			menu_principal();
			break;
	}
}



//pesquisar
int pesquisar(int lin){
	
	int cod;
	
	cout << "\nInforme o código do "<< tipo <<" que deseja pesquisar (-1 para retornar): ";
	cin >> cod;
	cin.sync();
	
	if(cod == -1){
		
		return 0;
	}
	
	for(int col = 0; col < 1000; col++){
		
		if(cod == col){
			
			if(banco[lin][col].nome == " "){
		
				cout << "\nCódigo não encontrado! \n";
				break;
			}
			
			ficha(lin, col);
		}
	}
	
	do{
		cout << "\n1. Voltar \n2. Pesquisar outro "<< tipo <<"\n3. Menu principal \n=> ";
		cin >> op3;
		
	}while(op3 > 3 and op3 < 1);
	
	
	switch(op3){
		
		case 2:
			pesquisar(linha);
			break;
		
		case 3:
			menu_principal();
			break;
	}
}



//cadastrar
int cadastrar(int lin){
	
	for(int col = 0; col < 1000; col++){
		
		if(banco[lin][col].nome == " "){
			
			cout << "\n============== "<< tipo << " cod. " << col <<" ==============\n" ;
			
			cout <<"Nome: ";
			getline(cin, banco[lin][col].nome);
			
			if(lin == 0 or lin == 1){  //dados dos produtos
		
				cout << "\nMarca: ";
				getline(cin, banco[lin][col].marca);
				
				cout << "\nPreço: R$ ";
				cin >> banco[lin][col].preco;
				cin.sync();
				
				cout << "\nSite: "; 
				getline(cin, banco[lin][col].site);
				
				cout << "\nVendidos: ";
				cin >> banco[lin][col].vend;
				cin.sync();
				
				cout << "\nDisponível: ";
				cin >> banco[lin][col].disp;
				cin.sync();
			
			}else if(lin == 2){  //dados dos clientes
			
				cout << "\nCPF: ";
				getline(cin, banco[lin][col].cpf);
				
				cout << "\nE-mail: "; 
				getline(cin, banco[lin][col].email);
				
				cout << "\nTelefone: "; 
				getline(cin, banco[lin][col].telefone);
				
				cout << "\nData de nascimento: "; 
				getline(cin, banco[lin][col].nasc);
				
			}else if(lin == 3){  //dados dos fornecedores
				
				cout << "\nCNPJ: "; 
				getline(cin, banco[lin][col].cnpj);
				
				cout << "\nE-mail: ";
				getline(cin, banco[lin][col].email);
				
				cout << "\nTelefone: ";
				getline(cin, banco[lin][col].telefone);
				
				cout << "\nProdutos fornecidos: " << banco[lin][col].prod;
				
			}else if(lin == 4){  //dados dos parceiros
				
				cout << "\n2. CNPJ: ";
				getline(cin, banco[lin][col].cnpj);
				
				cout << "\n3. E-mail: ";
				getline(cin, banco[lin][col].email);
				
				cout << "\n4. Telefone: ";
				getline(cin, banco[lin][col].telefone);
				//cout << "\nProdutos anunciados: ";
			}
			
			break;
		}
	}
	
	do{
		cout << "\n1. Voltar \n2. Cadastrar outro "<< tipo <<"\n3. Menu principal \n=> ";
		cin >> op3;
		
	}while(op3 > 3 or op3 < 1);
	
	
	switch(op3){
		
		case 2:
			cadastrar(linha);
			break;
		
		case 3:
			menu_principal();
			break;
	}
	
}


//atualizar
int atualizar(int lin){
	
	int cod, mod;
	
	system("cls");
	
	cout << "ATUALIZAR \n";
	
	cout << "\nInforme o código do "<< tipo <<" que deseja atualizar (-1 para retornar): ";
	cin >> cod;
	cin.sync();
	
	if(cod == -1){
		
		return 0;
	}
	
	for(int col = 0; col < 1000; col++){
		
		if(cod == col){
			
			if(banco[lin][col].nome == " "){
		
				cout << "\nCódigo não encontrado!\n";
				break;
			}
			
			ficha(lin, col);
			
			cout << "Qual informação deseja alterar? \n=> ";
			cin >> mod;
			cin.sync();
			
			
			cout << "Alterar ";
			
			switch(mod){
				
				case 1:  //alterar o nome
					
					cout << "nome: ";
					getline(cin, banco[lin][col].nome);
					
					break;
					
				case 2:  //alterar a marca, o cpf ou o cnpj
					
					if(lin == 0 or lin == 1){
						cout << "marca: ";
						getline(cin, banco[lin][col].marca);
					
					}else if(lin == 2){
						cout << "CPF (xxx.xxx.xxx-xx): ";
						getline(cin, banco[lin][col].cpf);
					
					}else if(lin == 3 or lin == 4){
						cout << "CNPJ: ";
						getline(cin, banco[lin][col].cnpj);
					}	
					break;
					
				case 3:  //alterar o preço ou o email
					
					if(lin == 0 or lin == 1){
						cout << "preço: ";
						cin >> banco[lin][col].preco;
						cin.sync();
					
					}else if(lin == 2 or lin == 3 or lin == 4){
						cout << "e-mail: ";
						getline(cin, banco[lin][col].email);
					}
					break;
				
				case 4:  //alterar site ou telefone
					
					if(lin == 0 or lin == 1){
						cout << "site: ";
						getline(cin, banco[lin][col].site);
						
					}else if(lin == 2 or lin == 3 or lin == 4){
						cout << "telefone ((xx)9 xxxx-xxxx): ";
						getline(cin, banco[lin][col].telefone);
					}
					break;
					
				case 5:  //alterar a quantidade de vendidos, a data de nascimento ou o produto fornecido
					
					if(lin == 0 or lin == 1){
						cout << "total vendido: ";
						cin >> banco[lin][col].vend;
						cin.sync();
						
					}else if(lin == 2){
						cout << "data de nascimento(dd/mm/aaaa): ";
						getline(cin, banco[lin][col].nasc);
					
					}else if(lin == 3){
						cout << "produtos fornecidos: ";
						getline(cin, banco[lin][col].prod);
					}
					break;
				
				case 6: //alterar quantidade disponível
					
					if(lin == 0 or lin == 1){
						cout << " total disponível: ";
						cin >> banco[lin][col].disp;
						cin.sync();
					}
					break;
			}
		}
	}
	
	do{
		cout << "\n1. Voltar \n2. Atualizar outro "<< tipo <<"\n3. Menu principal \n=> ";
		cin >> op3;
		
	}while(op3 > 3 or op3 < 1);
	
	
	switch(op3){
		
		case 2:
			atualizar(linha);
			break;
		
		case 3:
			menu_principal();
			break;
	}
}



//excluir
int excluir(int lin){
	
	int cod, exc;
	
	cout << "Código do "<< tipo <<" para excluir (-1 para retornar): ";
	cin >> cod;
	cin.sync();
	
	if(cod == -1){
		
		return 0;
	}
	
	for(int col = 0; col < 1000; col++){
		
		if(col == cod){
			
			if(banco[lin][col].nome == " "){
		
				cout << "\nCódigo não encontrado! \n";
				break;
			}
		
			ficha(lin, col);
			
			cout << "Deseja excluir esse? "<< tipo <<" \n0. Não 1. Sim \n=>";
			cin >> exc;
			cin.sync();
			
			if(exc == 1){
				
				banco[lin][col].nome = " ";
			}
		}
	}
	
	do{
		cout << "1. Voltar \n2. Excluir outro "<< tipo <<"\n3. Menu principal \n=> ";
		cin >> op3;
		
	}while(op3 > 3 and op3 < 1);
	 
	switch(op3){
		
		case 2:
			excluir(linha);
			break;
		
		case 3:
			menu_principal();
			break;
	}
}


void opcoes(){
	
	
	switch(op2){
		
		case 1:
			
			listar(linha);
			break;
		
		case 2:
			
			pesquisar(linha);
			break;
			
		case 3:
			
			cadastrar(linha);
			break;
			
		case 4:
			
			atualizar(linha);
			break;
			
		case 5:
			
			excluir(linha);
			break;
		
		case 6:
			menu_principal();
			break;
	}
}


//INÍCIO DO PROGRAMA!!!

int main(int argc, char** argv) {

    setlocale(LC_ALL, "Portuguese");
    
    
    //definindo todos os nome como " "
    for(int l = 0; l < 5;l++){
    	
    	for(int c = 0; c < 1000; c++){
    		
    		banco[l][c].nome = " ";
		}
	}
    
    
    //"BANCO DE DADOS"
    
    //hardwares
    banco[0][0].nome = "";  banco[0][0].marca = "";  banco[0][0].preco = 0;  banco[0][0].site = "Mercado Livre"; banco[0][0].disp = 0; banco[0][0].vend = 0;
    banco[0][1].nome = "";  banco[0][1].marca = "";  banco[0][1].preco = 0;  banco[0][1].site = "Mercado Livre"; banco[0][1].disp = 0; banco[0][1].vend = 0;
    banco[0][2].nome = "";  banco[0][2].marca = "";  banco[0][2].preco = 0;  banco[0][2].site = "Mercado Livre"; banco[0][2].disp = 0; banco[0][2].vend = 0;
    banco[0][3].nome = "";  banco[0][3].marca = "";  banco[0][3].preco = 0;  banco[0][3].site = "Mercado Livre"; banco[0][3].disp = 0; banco[0][3].vend = 0;
    banco[0][4].nome = "";  banco[0][4].marca = "";  banco[0][4].preco = 0;  banco[0][4].site = "Mercado Livre"; banco[0][4].disp = 0; banco[0][4].vend = 0;
    banco[0][5].nome = "";  banco[0][5].marca = "";  banco[0][5].preco = 0;  banco[0][5].site = "Mercado Livre"; banco[0][5].disp = 0; banco[0][5].vend = 0;
    banco[0][6].nome = "";  banco[0][6].marca = "";  banco[0][6].preco = 0;  banco[0][6].site = "Mercado Livre"; banco[0][6].disp = 0; banco[0][6].vend = 0;
    banco[0][7].nome = "";  banco[0][7].marca = "";  banco[0][7].preco = 0;  banco[0][7].site = "Mercado Livre"; banco[0][7].disp = 0; banco[0][7].vend = 0;
    banco[0][8].nome = "";  banco[0][8].marca = "";  banco[0][8].preco = 0;  banco[0][8].site = "Mercado Livre"; banco[0][8].disp = 0; banco[0][8].vend = 0;
    banco[0][9].nome = "";  banco[0][9].marca = "";  banco[0][9].preco = 0;  banco[0][9].site = "Mercado Livre"; banco[0][9].disp = 0; banco[0][9].vend = 0;
    
    
    
	//periféricos
	banco[1][0].nome = "";  banco[1][0].marca = "";  banco[1][0].preco = 0;  banco[1][0].site = "Mercado Livre"; banco[1][0].disp = 0; banco[1][0].vend = 0;
    banco[1][1].nome = "";  banco[1][1].marca = "";  banco[1][1].preco = 0;  banco[1][1].site = "Mercado Livre"; banco[1][1].disp = 0; banco[1][1].vend = 0;
    banco[1][2].nome = "";  banco[1][2].marca = "";  banco[1][2].preco = 0;  banco[1][2].site = "Mercado Livre"; banco[1][2].disp = 0; banco[1][2].vend = 0;
    banco[1][3].nome = "";  banco[1][3].marca = "";  banco[1][3].preco = 0;  banco[1][3].site = "Mercado Livre"; banco[1][3].disp = 0; banco[1][3].vend = 0;
    banco[1][4].nome = "";  banco[1][4].marca = "";  banco[1][4].preco = 0;  banco[1][4].site = "Mercado Livre"; banco[1][4].disp = 0; banco[1][4].vend = 0;
    banco[1][5].nome = "";  banco[1][5].marca = "";  banco[1][5].preco = 0;  banco[1][5].site = "Mercado Livre"; banco[1][5].disp = 0; banco[1][5].vend = 0;
    banco[1][6].nome = "";  banco[1][6].marca = "";  banco[1][6].preco = 0;  banco[1][6].site = "Mercado Livre"; banco[1][6].disp = 0; banco[1][6].vend = 0;
    banco[1][7].nome = "";  banco[1][7].marca = "";  banco[1][7].preco = 0;  banco[1][7].site = "Mercado Livre"; banco[1][7].disp = 0; banco[1][7].vend = 0;
    banco[1][8].nome = "";  banco[1][8].marca = "";  banco[1][8].preco = 0;  banco[1][8].site = "Mercado Livre"; banco[1][8].disp = 0; banco[1][8].vend = 0;
    banco[1][9].nome = "";  banco[1][9].marca = "";  banco[1][9].preco = 0;  banco[1][9].site = "Mercado Livre"; banco[1][9].disp = 0; banco[1][9].vend = 0;
	
	//clientes
	banco[2][0].nome = "Lucas Vicente Araújo";    banco[2][0].cpf = "938.062.905-20";  banco[2][0].email = "nicolasvicente@mucoucah.com.br";   banco[2][0].telefone = "(86) 99465-0354";	banco[2][0].nasc = "19/04/1980";
	banco[2][1].nome = "Raul Renan Iago Souza";	  banco[2][1].cpf = "947.442.277-08";  banco[2][1].email = "raulrenansouza@sandvik.com";	   banco[2][1].telefone = "(86) 98563-3863";	banco[2][1].nasc = "09/03/1998";	
	banco[2][2].nome = "Juan Iago Almeida";	      banco[2][2].cpf = "254.189.673-55";  banco[2][2].email = "juan.iago.almeida@paae.com.br";    banco[2][2].telefone = "(91) 99730-8709";	banco[2][2].nasc = "14/02/1990";	
	banco[2][3].nome = "Bernardo Cauê Martins";   banco[2][3].cpf = "881.487.968-07";  banco[2][3].email = "bernardomartins@tecsysbrasil.com"; banco[2][3].telefone = "(27) 99861-0437";	banco[2][3].nasc = "01/01/1988";	
	banco[2][4].nome = "Liz Elaine Cavalcanti";	  banco[2][4].cpf = "205.483.956-67";  banco[2][4].email = "liz_cavalcanti@engeco.com.br";	   banco[2][4].telefone = "(96) 99951-0074";	banco[2][4].nasc = "08/01/1994";	
	banco[2][5].nome = "Natália Larissa Lopes";	  banco[2][5].cpf = "027.599.610-79";  banco[2][5].email = "natalia-lopes76@sabesp.com.br";	   banco[2][5].telefone = "(85) 98227-0547";	banco[2][5].nasc = "12/03/1985";	
	banco[2][6].nome = "Luiza Silva Brito";	      banco[2][6].cpf = "568.175.482-09";  banco[2][6].email = "luzia_brito@lhp.com.br";           banco[2][6].telefone = "(96) 98196-2099";	banco[2][6].nasc = "14/02/2001";
	banco[2][7].nome = "Edson Thiago Gomes";      banco[2][7].cpf = "963.958.042-27";  banco[2][7].email = "edsongomes@siexpress.com.br";	   banco[2][7].telefone = "(61) 98952-8160";	banco[2][7].nasc = "07/02/1990";	
	banco[2][8].nome = "Manoel Kevin Silveira";	  banco[2][8].cpf = "104.131.977-00";  banco[2][8].email = "manoel_silveira@mailinator.com";   banco[2][8].telefone = "(47) 98585-1845";	banco[2][8].nasc = "15/01/1995";	
	banco[2][9].nome = "Nelson Henrique Rezende"; banco[2][9].cpf = "828.807.182-10";  banco[2][9].email = "nelsonrezende96@beminvestir.com";  banco[2][9].telefone = "(61) 99747-3449";	banco[2][9].nasc = "10/03/1983";		
	
	//fornecedores
	banco[3][0].nome = "GPJ"; banco[3][0].telefone = "(31) 2519-0401";  banco[3][0].email = "gpj@contato.com.br";  banco[3][0].cnpj = "06.697.988/0001-76";
	
	
	//parceiros
	banco[4][0].nome = "Mercado Livre";  banco[4][0].telefone = "0800-637-7246";  banco[4][0].email = "mercadolivre@contato.com.br";  banco[4][0].cnpj = "03.499.243/0001-04";
	
	menu_principal();
	
	while(op1 != 7){
		
		//menu_principal();
		
		system("cls");
		
		switch(op1){
		
		case 1:
			
			cout << "PRODUTOS \n";
			subMenu();
			break;
		
		case 2:
			
			cout << "CLIENTES \n";
			subMenu();
			
			linha = 2;
			tipo = "cliente";
			
			opcoes();
			break;
		
		case 3:
			
			cout << "FORNECEDORES \n";
			subMenu();
			
			linha = 3;
			tipo = "fornecedor";
			
			opcoes();
			break;
		
		case 4:
			
			cout << "PARCEIROS \n";
			subMenu();
			
			linha = 4;
			tipo = "parceiro";
			
			opcoes();
			break;
		
		case 5:
			
			cout << "AJUDA";
			break;
		
		case 6:
			
			cout << "SOBRE";
			break;
		
		case 7:
			
			"Logoff";
			break;
			
		}
		
	}
	
    cout << "\n \n";
    system("pause");

    //return 0;
}

