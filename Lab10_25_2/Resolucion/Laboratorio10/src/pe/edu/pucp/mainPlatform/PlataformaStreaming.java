package pe.edu.pucp.mainPlatform;

import pe.edu.pucp.channel.CanalStreaming;
import pe.edu.pucp.register.Registro;
import pe.edu.pucp.subscription.Suscripcion;
import pe.edu.pucp.subscription.*;
import pe.edu.pucp.user.Usuario;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class PlataformaStreaming {
    private final List<CanalStreaming> canales;
    private final List<Usuario> usuarios;
    private final List<Suscripcion> suscripciones;
    private final Scanner archivo;

    public PlataformaStreaming(String ruta) throws FileNotFoundException {
        canales = new ArrayList<>();
        usuarios = new ArrayList<>();
        suscripciones = new ArrayList<>();
        archivo = new Scanner(new File(ruta));
    }

    public void cargarDatos() {
        this.cargarCanales();
        this.cargarUsuarios();
        this.cargarSuscripciones();
    }

    public void cargarUsuarios() {
        Registro registro2;
        while(true) {
            registro2 = new Usuario();
            if (!registro2.leer(archivo))break;
            usuarios.add((Usuario) registro2);
        }
        String cadena = archivo.next();
    }

    public void cargarCanales() {
        Registro registro1;
        while(true) {
            registro1 = new CanalStreaming();
            if (!registro1.leer(archivo)) break;
            canales.add((CanalStreaming) registro1);
        }
        String cadena = archivo.next();
    }

    public void cargarSuscripciones() {
        String tipo;
        while(archivo.hasNext()) {
            tipo = archivo.next();
            Suscripcion registro3 = null;
            if (tipo.equals("VIP")) {
                registro3 = new SuscripcionVIP();
            } else if (tipo.equals("BASICA")) {
                registro3 = new SuscripcionBasica();
            } else if (tipo.equals("PREMIUM")) {
                registro3 = new SuscripcionPremium();
            }

            boolean leido = registro3.leer(archivo);
            suscripciones.add((Suscripcion) registro3);
        }
        completarDatosRestantes();
    }

    private void completarDatosRestantes() {
        // Completar Usuarios
        for (Suscripcion suscripcion : suscripciones) {
            suscripcion.completarDatos(usuarios,canales);
        }

        // Completar suscripciones
        for (Usuario user : usuarios) {
            for (Suscripcion sub : suscripciones) {
                if (user.getId() == sub.getIdUsuario()) {
                    user.getSuscripciones().add(sub);
                }
            }
        }
    }

    public void imprimirReporte() {

        imprimeLinea('=', 150);
        String titulo = "REPORTE DE USUARIOS";
        int espaciosIzquierda = (150 - titulo.length()) / 2;

        for (int i = 0; i < espaciosIzquierda; i++) {
            System.out.printf(" ");
        }
        System.out.println(titulo);

        imprimeLinea('=', 150);

        System.out.println("ID    Nombre Completo        DNI         Edad  Ciudad      "
                + "       F.Nac              Teléfono     Email                   Ocupación");
        imprimeLinea('-', 150);

        for (Usuario user : usuarios) {
            user.imprimir();
            System.out.println();
        }

        // Opcional
        imprimeLinea('=', 150);
        System.out.println("FELIZ NAVIDAD!");
        imprimeLinea('=', 150);
    }

    private void imprimeLinea(char c, int n) {
        for (int i = 0; i < n; i++) {
            System.out.print(c);
        }

        System.out.println();
    }

}
