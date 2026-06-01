/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  sacoe
 * Modified: martes, 12 de mayo de 2026 18:39:21
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/

#include "Nodo.h"

// Getters y Setters
Nodo* Nodo::getSiguiente() {
    return siguiente;
}

void Nodo::setSiguiente(Nodo* newSiguiente) {
    siguiente = newSiguiente;
}

Nodo* Nodo::getAnterior() {
    return anterior;
}

void Nodo::setAnterior(Nodo* newAnterior) {
    anterior = newAnterior;
}

Turno Nodo::getTurno() {
    return turno;
}

void Nodo::setTurno(Turno newTurno) {
    turno = newTurno;
}

Nodo::Nodo(Turno turno, Nodo* sig, Nodo* ant) {
    this->turno     = turno;
    this->siguiente = sig;
    this->anterior  = ant;
}

Nodo::Nodo(Turno turno, Nodo* sig) {
    this->turno     = turno;
    this->siguiente = sig;
    this->anterior  = nullptr;
}

Nodo::Nodo() {
    this->siguiente = nullptr;
    this->anterior  = nullptr;
}

Nodo::~Nodo() {
}
