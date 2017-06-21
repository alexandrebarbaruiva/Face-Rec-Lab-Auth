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
        Usuario userTest = Usuario("Alexandre", "Augusto", "0124567890", 1);
        Autenticador authTest = Autenticador("Gabriel", 1);
        Gerenciador gerTest = Gerenciador();

        REQUIRE(userTest.getNome() == "Alexandre");
        REQUIRE(userTest.getSobrenome() == "Augusto");
        REQUIRE(userTest.getCPF() == "0124567890");
        REQUIRE(userTest.getId() == 1);
        REQUIRE(userTest.pedirReserva(authTest, authTest.getToken()) == "Reserva feita com sucesso.");
        REQUIRE(userTest.requisitarAcesso(gerTest, 0) == 0);
        REQUIRE(userTest.requisitarAcesso(gerTest, 1) == 1);
        REQUIRE(userTest.requisitarAcesso(gerTest, 2) == 2);
        REQUIRE(userTest.requisitarAcesso(gerTest, 3) == 3);


        Usuario otherTest = Usuario();

        REQUIRE(otherTest.getNome() == "");
        REQUIRE(otherTest.getSobrenome() == "");
        REQUIRE(otherTest.getCPF() == "");
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

    SECTION("Verifica evento", "[Informação]"){
        Evento eventoTest = Evento("Django Jam");

        REQUIRE(eventoTest.getNomeEvento() == "Django Jam");
        eventoTest.setNomeEvento("Jungle Jazz");
        REQUIRE(eventoTest.getNomeEvento() == "Jungle Jazz");
        REQUIRE(
            eventoTest.adicionaParticipante("01234567890")
            == "Participante registrado com sucesso. Há 19 vagas disponíveis.");
        REQUIRE(
            eventoTest.removeParticipante("01234567890")
        == "Participante removido com sucesso. Há 20 vagas disponíveis.");

        Evento otherTest = Evento();
        REQUIRE(otherTest.getNomeEvento() == "");
        REQUIRE(
            otherTest.adicionaParticipante("01234567890")
            == "Participante registrado com sucesso. Há 19 vagas disponíveis.");


        std::cout<<"EVENTO OK"<<std::endl;
    }

    SECTION("Verifica Dia", "[Informação]"){
        Dia diaTest = Dia();
        Autenticador authTest = Autenticador("Gabriel", 1);

        REQUIRE(
            diaTest.mudaEvento(authTest, authTest.getToken(), "Novo evento.", 0)
            == "Evento alterado com sucesso.");
        REQUIRE(diaTest.mostraEvento(0) == "Novo evento.");
        REQUIRE(diaTest.mostraEvento(1) == "");
        REQUIRE(diaTest.mostraNomeDia() == "Segunda");
        std::cout<<"DIA OK"<<std::endl;
    }

    SECTION("Verifica semana", "[Informação]"){
        Semana semTest = Semana();
        Autenticador authTest = Autenticador("Gabriel", 1);

        REQUIRE(semTest.visualizaEventosSemana() == "OK.");
        semTest.mudaEvento(authTest, authTest.getToken(), "Evento Python BR", 0, 8);
        REQUIRE(semTest.visualizaEventosDia(0) == "OK.");
        REQUIRE(semTest.visualizaEventosSemana() == "OK.");
        std::cout<<"SEMANA OK"<<std::endl;

    }
    SECTION("Verifica sala", "[Informação]"){
        Sala salaTest = Sala();
        Autenticador authTest = Autenticador("Gabriel", 1);

        REQUIRE(salaTest.visualizaEventosSemana(0) == "OK.");
        REQUIRE(
            salaTest.mudaEvento(authTest, authTest.getToken(), "Evento Python USA", 0, 1, 8)
            == "Evento alterado com sucesso.");
        REQUIRE(salaTest.visualizaEventosSemana(0) == "OK.");
        REQUIRE(
            salaTest.mudaEventoRecorrente(authTest, authTest.getToken(), "Aula TP1", 0, 2, 1, 20)
            == "Evento alterado com sucesso.");
        REQUIRE(
            salaTest.mudaEventoRecorrente(authTest, authTest.getToken(), "Aula TP1", 0, 2, 3, 20)
            == "Evento alterado com sucesso.");
        REQUIRE(salaTest.visualizaEventosSemana(0) == "OK.");
        REQUIRE(salaTest.visualizaEventosSemana(1) == "OK.");
        REQUIRE(salaTest.visualizaEventosSemana(2) == "OK.");
        REQUIRE(salaTest.visualizaEventosSemana(3) == "OK.");
        std::cout<<"SALA OK"<<std::endl;
    }

    SECTION("Verifica Laboratorio", "[Informação]"){
        Laboratorio labTest = Laboratorio();

        REQUIRE(labTest.visualizaEventosDia() == "OK.");
        //(Nome do evento, semana, dia, horario, sala)
        REQUIRE(labTest.mudaEvento("Seminário OpenCV", 0, 3, 8, 0) == "Evento alterado com sucesso.");
        //(Nome do evento, semanaInicial, semanaFinal, dia, horario, sala)
        REQUIRE(labTest.mudaEventoRecorrente("Aula TP1", 0, 2, 1, 20, 0) == "Evento alterado com sucesso.");
        REQUIRE(labTest.mudaEventoRecorrente("Aula TP1", 0, 2, 3, 20, 0) == "Evento alterado com sucesso.");
        //(salaDesejada, semanaDesejada)
        REQUIRE(labTest.visualizaEventosSemana(0, 0) == "OK.");
        REQUIRE(labTest.visualizaEventosSemana(1, 0) == "OK.");
        REQUIRE(labTest.visualizaEventosSemana(0, 1) == "OK.");
        REQUIRE(labTest.visualizaEventosSemana(0, 2) == "OK.");

        std::cout<<"LABORATORIO OK"<<std::endl;
    }

}
