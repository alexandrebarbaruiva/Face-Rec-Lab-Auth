/*
class Usuario; //TODO: criar subclasses
class Autenticador; //antigo guardinha, responsável por permitir novos cadastros e agendamento
class Gerenciador; //antiga porta, responsável por permitir entrada a lab e salas
class BD; //onde ficam todos os dados de usuarios
class Laboratorio; //conjunto de salas
class Sala; //self explanatory
class Dia; //uma classe com struct de todos os eventos do dia
*/
/*

Tipos de usuários
-1: não cadastrado
0: genérico
1: professor (pode reservar qualquer evento, pode entrar somente nas salas designadas)
2: aluno (não pode reservar, pode entrar somente nas salas designadas)
3: palestrante (pode reservar somente eventos únicos, pode entrar somente nas salas designadas)
4: funcionario (pode reservar qualquer evento, pode entrar em tudo)

*/

class Usuario{
	private:
		std::string nome;
    	std::string sobrenome;
		std::string cpfOuMatricula;
		int id;
    //TODO: fotos[]


    public:
        Usuario(){
			nome = "";
		    sobrenome = "";
			cpfOuMatricula = "";
		    id = -1;
		}
		Usuario(std::string novoNome, std::string novoSobrenome, std::string novoCPFouMatricula, int novoId){
			nome = novoNome;
		    sobrenome = novoSobrenome;
			cpfOuMatricula = novoCPFouMatricula;
			id = novoId;
		}

		std::string getNome(void){
			return nome;
		}
		std::string getSobrenome(void){
			return sobrenome;
		}
		std::string getCPFouMatricula(){
			return cpfOuMatricula;
		}
		int getId(void){
			return id;
		}
	    //pedirReserva(Sala sala, int horario, int grauDeAcesso, Autenticador autenticador);
        //pedirEntrada(int salaEscolhida);
        //pedirAcessoMaior();
};











/*
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
*/
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

class guardinha{

	permitirAcesso(user)

}

class porta{
	func abrir -> "acesso permitido" (abre porta)
	func erro -> "acesso negado"
}
*/
