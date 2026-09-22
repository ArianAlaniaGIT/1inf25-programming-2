package pe.edu.pucp.register;

import java.io.FileNotFoundException;
import java.util.Scanner;

public abstract class Registro {
    public abstract boolean leer(Scanner sc);
    public abstract void imprimir();
}
