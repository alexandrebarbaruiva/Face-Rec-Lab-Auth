/*
class Usuario; //TODO: criar subclasses
class Autenticador; //antigo guardinha, responsável por permitir novos cadastros e agendamento
class Gerenciador; //antiga porta, responsável por permitir entrada a lab e salas
class Laboratorio; //conjunto de salas
class Sala; //self explanatory
*/
/*
Tipo de usuários
-1: não cadastrado
0: genérico
1: professor
2: aluno

*/

class Usuario{
	string nome;
    string sobrenome;
	string cpfOuMatricula;

    int tipo;
	int acesso; /* verificar se vai pro diagrama*/
    //TODO: fotos[]


    public:
        Usuario();
	    pedirReserva(Sala sala, int horario, int grauDeAcesso, Autenticador autenticador);
        pedirEntrada(int salaEscolhida);
        pedirAcessoMaior();

}
Usuario::Usuario(void){
    this.nome = "Not a person";
    this.sobrenome = "";
    this.cpfOuMatricula = "Not a number";
    this.tipo = -1;
    this.acesso = -1;
}
Usuario::Usuario(string novoNome, string novoSobrenome, string novoId){
    this.nome = novoNome;
    this.sobrenome = "";
    this.cpfOuMatricula = "Not a number";
    this.tipo = 0;
    this.acesso = 0;
}
Usuario::pedirReserva(void){
    nome = "Not a person";
    cpf = "Not a number";
}
Usuario::pedirEntrada(int salaEscolhida){
    if (this.acesso > 100 ) {
        processo(salaEscolhida, true);
    } else if (this.acesso > 10) {
        if(salaEscolhida == 1 and (this.acesso == 12 or this.acesso == 13)){
            processo(salaEscolhida, true);
        }
        else if(salaEscolhida == 2 and (this.acesso == 12 or this.acesso == 23)){
            processo(salaEscolhida, true);
        }
        else if(salaEscolhida == 3 and (this.acesso == 13 or this.acesso == 23)){
            processo(salaEscolhida, true);
        }
        else{
            processo(salaEscolhida, true);
        }
    } else {
        if(acesso == salaEscolhida){
            processo(salaEscolhida, true);
        }
        else{
            processo(salaEscolhida, false);
        }
    }

}

/*
class reserva{
	user
	sala
	horario
	duracao
	proposito
	users[]
}

class aula{
	disciplina
	dias[]
	horario
	duracao
	alunos
	professor
	id
	turma
	sala
}


class laboratorio{
	users_cadastrados[]
	user
	porta
	guarda
	reservas

	adicionarUser()
	removerUser()

	autenticar(user)
		portao.abrir ou portao.fechar
	{
		se user.tipo == aluno, verifica nas aulas

	}
}

class Autenticador{
	string Nome;
	char Turno;
	string senha;
	
	public:
		criarUsuario();
		removerUsuario();
		aumentarPermissão();
		fazerReserva();

}

class Gerenciador{
	
	public:
		permitirAcesso();
		requisitaMaisFotos();
		requisitaAutenticador();
		requisitaVisual();
		verificaInfoUser();
}
*/
