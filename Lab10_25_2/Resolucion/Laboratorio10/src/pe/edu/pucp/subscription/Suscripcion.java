package pe.edu.pucp.subscription;

import pe.edu.pucp.channel.CanalStreaming;
import pe.edu.pucp.register.Registro;
import pe.edu.pucp.user.Usuario;

import java.util.List;
import java.util.Scanner;

public abstract class Suscripcion extends Registro {
    private int idUsuario;
    private int idCanal;
    private Usuario usuario;
    private CanalStreaming canal;


    public Suscripcion() {
        idUsuario = 0;
        idCanal = 0;
        usuario = null;
        canal = null;
    }

    @Override
    public void imprimir() {
        System.out.printf(" | Usuario: %-2d   %-20s | Canal: %-2d   ", idUsuario,usuario.getNombreCompleto(),idCanal);
        canal.imprimir();
    }

    @Override
    public boolean leer(Scanner archivo) {
        idUsuario = archivo.nextInt();
        idCanal = archivo.nextInt();
        usuario = new Usuario();
        canal = new CanalStreaming();

        return true;
    }

    public void completarDatos(List<Usuario> usuarios, List<CanalStreaming> canales) {
        for (Usuario user : usuarios) {
            if (user.getId() == idUsuario) {
                usuario = user;
                break;
            }
        }

        for (CanalStreaming channel : canales) {
            if (channel.getId() == idCanal) {
                canal = channel;
                break;
            }
        }
    }

    public abstract String getTipo();

    public abstract double calcularPrecio();


    public int getIdUsuario() {
        return idUsuario;
    }

    public void setIdUsuario(int idUsuario) {
        this.idUsuario = idUsuario;
    }

    public int getIdCanal() {
        return idCanal;
    }

    public void setIdCanal(int idCanal) {
        this.idCanal = idCanal;
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }

    public CanalStreaming getCanal() {
        return canal;
    }

    public void setCanal(CanalStreaming canal) {
        this.canal = canal;
    }
}
