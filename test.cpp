#define CATCH_CONFIG_MAIN
#include "others/catch.hpp"
#include "funcoes.cpp"
#include "classes.cpp"

/*TEST_CASE("Verificação de interface de linha de comando") {

    SECTION("Verificação de acesso", "[porta liberada], [autorização]"){
        REQUIRE(permitirAcesso(0, false) == -1 );
        REQUIRE(permitirAcesso(0, true) == 0 );
        REQUIRE(permitirAcesso(1, false) == -1 );
        REQUIRE(permitirAcesso(1, true) == 1 );
        REQUIRE(permitirAcesso(2, false) == -1 );
        REQUIRE(permitirAcesso(2, true) == 2 );
        REQUIRE(permitirAcesso(3, false) == -1 );
        REQUIRE(permitirAcesso(3, true) == 3 );
        REQUIRE(permitirAcesso(100, false) == -1 );
        REQUIRE(permitirAcesso(100, true) == -1 );
        std::cout<<"ACESSO OK"<<std::endl;
    }
}*/

TEST_CASE("Verificação de classes") {

    SECTION("Verifica classe Usuário", "[Informação]" ){
        Usuario userTest = Usuario("Alexandre", "Augusto", "01245678900", 1);
        Autenticador authTest = Autenticador("Gabriel", 1);
        Gerenciador gerTest = Gerenciador();

        REQUIRE(userTest.getNome() == "Alexandre");
        REQUIRE(userTest.getSobrenome() == "Augusto");
        REQUIRE(userTest.getCPFouMatricula() == "01245678900");
        REQUIRE(userTest.getId() == 1);
        REQUIRE(userTest.pedirReserva(authTest, authTest.getToken()) == "Reserva feita com sucesso.");
        REQUIRE(userTest.requisitarAcesso(gerTest, 0) == 0);
        REQUIRE(userTest.requisitarAcesso(gerTest, 1) == 1);
        REQUIRE(userTest.requisitarAcesso(gerTest, 2) == 2);
        REQUIRE(userTest.requisitarAcesso(gerTest, 3) == 3);


        Usuario otherTest = Usuario();

        REQUIRE(otherTest.getNome() == "");
        REQUIRE(otherTest.getSobrenome() == "");
        REQUIRE(otherTest.getCPFouMatricula() == "");
        REQUIRE(otherTest.getId() == -1);

        std::cout<<"USUARIO OK"<<std::endl;
    }

    SECTION("Verifica classe autenticador", "[Informação]"){

        Autenticador authTest = Autenticador("Gabriel", 1);

        REQUIRE(authTest.getNome() == "Gabriel");
        REQUIRE(authTest.getId() == 1);
        authTest.mudaSenha("novaSenha","padrao5000");
        //REQUIRE(authTest.senha == "novaSenha");
        authTest.mudaSenha("outraSenha","padrao5000");
        //REQUIRE(authTest.senha == "novaSenha");


        Autenticador otherTest = Autenticador();

        REQUIRE(otherTest.getNome() == "");
        REQUIRE(otherTest.getId() == -1);
        otherTest.mudaSenha("novaSenha","");
        //REQUIRE(otherTest.senha == "");
        std::cout<<"AUTENTICADOR OK"<<std::endl;
    }

    SECTION("Verifica classe gerenciador", "[Informação]"){
        Gerenciador gerTest = Gerenciador();
        REQUIRE(gerTest.permitirAcesso(0, false) == -1);
        REQUIRE(gerTest.permitirAcesso(0, true) == 0);
        REQUIRE(gerTest.permitirAcesso(1, false) == -1);
        REQUIRE(gerTest.permitirAcesso(1, true) == 1);

        std::cout<<"GERENCIADOR OK"<<std::endl;
    }

    SECTION("Verifica Dia", "[Informação]"){
        Dia diaTest = Dia();
        Autenticador authTest = Autenticador("Gabriel", 1);

        REQUIRE(diaTest.mudaEvento(authTest, authTest.getToken(), "Novo evento.", 0) == "Evento alterado com sucesso.");
        REQUIRE(diaTest.mostraEvento(0) == "Novo evento.");
        REQUIRE(diaTest.mostraEvento(1) == "");
        REQUIRE(diaTest.mostraNomeDia() == "Segunda");
        std::cout<<"DIA OK"<<std::endl;
    }

    SECTION("Verifica semana", "[Informação]"){
        Semana semTest = Semana();
        Autenticador authTest = Autenticador("Gabriel", 1);

        REQUIRE(semTest.visualizaEventos() == "OK.");
        semTest.mudaEvento(authTest, authTest.getToken(), "Evento Python BR", 0, 8);
        REQUIRE(semTest.visualizaEventos() == "OK.");
        std::cout<<"SEMANA OK"<<std::endl;

    }
    SECTION("Verifica sala", "[Informação]"){
        Sala salaTest = Sala();
        Autenticador authTest = Autenticador("Gabriel", 1);

        REQUIRE(salaTest.visualizaEventos(0) == "OK.");
        REQUIRE(salaTest.mudaEvento(authTest, authTest.getToken(), "Evento Python USA", 0, 1, 8) == "Evento alterado com sucesso.");
        REQUIRE(salaTest.visualizaEventos(0) == "OK.");
        REQUIRE(salaTest.mudaEventoRecorrente(authTest, authTest.getToken(), "Aula TP1", 0, 2, 1, 20) == "Evento alterado com sucesso.");
        REQUIRE(salaTest.mudaEventoRecorrente(authTest, authTest.getToken(), "Aula TP1", 0, 2, 3, 20) == "Evento alterado com sucesso.");
        REQUIRE(salaTest.visualizaEventos(0) == "OK.");
        REQUIRE(salaTest.visualizaEventos(1) == "OK.");
        REQUIRE(salaTest.visualizaEventos(2) == "OK.");
        REQUIRE(salaTest.visualizaEventos(3) == "OK.");
        std::cout<<"SALA OK"<<std::endl;
    }
    /*SECTION("Verifica Laboratorio", "[Informação]"){
        Laboratorio labTest = Laboratorio();
        REQUIRE(labTest.permitirAcesso(0, false) == -1);

        std::cout<<"LABORATORIO OK"<<std::endl;
    }*/

}
