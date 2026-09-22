package pe.edu.pucp.user;

import pe.edu.pucp.register.Registro;
import pe.edu.pucp.subscription.Suscripcion;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Usuario extends Registro {

    private int id;
    private String nombreCompleto;
    private int dni;
    private int edad;
    private String ciudad;
    private String fechaNacimiento;
    private String telefono;
    private String email;
    private String ocupacion;
    private final List<Suscripcion> suscripciones;


    public Usuario() {
        id = 0;
        nombreCompleto = "";
        dni = 0;
        edad = 0;
        ciudad = "";
        fechaNacimiento = "";
        telefono = "";
        email = "";
        ocupacion = "";
        suscripciones = new ArrayList<>();
    }

    public double calcularCosto() {
        double costo = 0.00;
        for (Suscripcion sub : suscripciones) {
            costo += sub.calcularPrecio();
        }
        return costo;
    }

    @Override
    public boolean leer(Scanner arch) {
        if (arch.hasNext("FIN")) return false;
        id = arch.nextInt();
        nombreCompleto = arch.next();
        dni = arch.nextInt();
        edad = arch.nextInt();
        ciudad = arch.next();
        fechaNacimiento = arch.next();
        telefono = arch.next();
        email = arch.next();
        ocupacion = arch.next();

        return true;
    }

    @Override
    public void imprimir() {
        System.out.printf("%2d    %-20s   %d    %d    %-15s    %-15s    %-10s    %-20s    %-15s\n", id,nombreCompleto,dni,edad,ciudad,fechaNacimiento,telefono,email,ocupacion);
        System.out.println("   Suscripciones:");
        for (Suscripcion sub : suscripciones) {
            System.out.printf("     - %-10s ", sub.getTipo());
            sub.imprimir();
            System.out.printf(" | Precio: %.2f\n", sub.calcularPrecio());
        }
        System.out.printf("   Costo Total: %.2f\n",calcularCosto());
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombreCompleto() {
        return nombreCompleto;
    }

    public void setNombreCompleto(String nombreCompleto) {
        this.nombreCompleto = nombreCompleto;
    }

    public int getDni() {
        return dni;
    }

    public void setDni(int dni) {
        this.dni = dni;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public String getCiudad() {
        return ciudad;
    }

    public void setCiudad(String ciudad) {
        this.ciudad = ciudad;
    }

    public String getFechaNacimiento() {
        return fechaNacimiento;
    }

    public void setFechaNacimiento(String fechaNacimiento) {
        this.fechaNacimiento = fechaNacimiento;
    }

    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getOcupacion() {
        return ocupacion;
    }

    public void setOcupacion(String ocupacion) {
        this.ocupacion = ocupacion;
    }

    public List<Suscripcion> getSuscripciones() {
        return suscripciones;
    }

}
