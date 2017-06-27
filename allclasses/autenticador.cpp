

//antigo guardinha, responsável por permitir novos cadastros e agendamento

/** @brief Classe responsável por autenticar reservas de salas e possíveis erros
* com a identificação facial.
*
* Além disso, somente é possível registrar novos usuários com a presença
* de um autenticador. O mesmo vale para modificação de informações de usuários.
* Sem um autenticador, somente é possível entrar e sair dos laboratórios.
*
* É possível que um usuário seja um autenticador, contudo haverá dois registros diferentes
* para a mesma pessoa no sistema.
*/
class Autenticador{
private:
	std::string nome;
	std::string senha; //para pedir outro token e acessar outras infos
	std::string token; //para fazer reserva
	int id;
public:
	/**
	* Construtor de autenticador vazio, lê de JSON.
	*/
	Autenticador(){
		//mudar pra ler info de JSON
		nome = "";
		senha = "";
		id = -1;
		token = "0";
	}

	/**
	* Construtor de autenticador válido, o token é gerado automaticamente e a senha
	* é padrão para todos, a mudança de senha deve ocorrer no ato do registro de um
	* novo autenticador.
	*/
	Autenticador(std::string novoNome, int novoId){
		nome = novoNome;
		senha = "padrao5000";
		id = novoId;
		token = geradorToken();
	}
	std::string getNome(void){
		return nome;
	}
	/**
	* Informação inútil por enquanto, quando implementar JSON vai ser maravilhoso.
	*/
	int getId(void){
		return id;
	}
	std::string mudaSenha(std::string novaSenha, std::string antigaSenha){
		if (senha == antigaSenha and id != -1){
			senha = novaSenha;
			return "Senha mudada com sucesso.";
		}
		else if (id == -1) {
			return "Usuário não registrado adequadamente.";
		}
		else{
			return "Senha errada, tente novamente.";
		}
	}
	std::string geradorToken(void){
		std::string token;
		static const char letras[] =
					"0123456789"
					"!@#$%^&*"
					"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
					"abcdefghijklmnopqrstuvwxyz";
		int tamanho = sizeof(letras) - 1;

		for (int i = 0; i < 13; i++){
			token += letras[rand() % tamanho];
		}
		return token;
	}
	std::string getToken(void){
		return token;
	}
};
