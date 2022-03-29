// #include <>
// #include ""


int main() {

  // Clases: Jugador, Torneo, Categoria, -CIRCUITO-


  int opc; cin >> opc;
  while (opc != 11) {
    if (opc == 1) {

      nuevo_jugador(p);
    }

    else if (opc == 2) {

      nuevo_torneo(t, c);
    }

    else if (opc == 3) {

      baja_jugador(p);
    }

    else if (opc == 4) {

      baja_torneo(t);
    }

    else if (opc == 5) {

      iniciar_torneo(t);
    }

    else if (opc == 6) {

      finalizar_torneo(t);
    }

    else if (opc == 7) {

      listar_ranking();
    }

    else if (opc == 8) {

      listar_jugadores();
    }

    else if (opc == 9) {

      listar_torneos();
    }

    else if (opc == 10) {

      listar_categorias();
    }

    cin >> opc;
  }
}
