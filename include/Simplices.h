#ifndef THICKER_TRIANGULATION_H
#define THICKER_TRIANGULATION_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>


/*
**************************SIMPLEX BASE ********************************
*/
class SimplexBase
{
public:
    SimplexBase(unsigned int id_in);
    ~SimplexBase();


    const unsigned int get_id() const { return id; }
    virtual const bool is_valid();

private:
    

protected:
    const unsigned int id;

};

SimplexBase::SimplexBase(unsigned int id_in)
    : id(id_in)
{
}

/*
**************************VERTEX ********************************
*/
class Vertex : public SimplexBase
{
public:
    Vertex(double x_in, double y_in, double z_in, unsigned int id_in);
    ~Vertex() = default;
    void print() const { std::cout << "Vertex " << this->get_id() << std::endl;}
    const std::vector<double> get_coordinates() const;
    const bool is_valid() const;
    const bool operator== (const Vertex& vertex_1) const;
    const bool operator!= (const Vertex& vertex_1) const;

private:
    const double x;
    const double y;
    const double z;
};

Vertex::Vertex(const double x_in, const double y_in, const double z_in, unsigned int id_in)
    : SimplexBase(id_in), x(x_in), y(y_in), z(z_in)
{
}

/*
**************************EDGE ********************************
*/
class Edge : public SimplexBase
{
public:
    Edge(unsigned int id_in, const Vertex vertex_1_in, const Vertex vertex_2_in);
    ~Edge() = default;
    void print() { std::cout << "Edge " << this->get_id() << std::endl;}
    const std::vector<Vertex> get_vertices() const;
    const bool is_valid() const;
    const bool operator== (const Edge &edge_1) const;
    const bool operator!= (const Edge &edge_1) const;

private:
    const Vertex &vertex_1;
    const Vertex &vertex_2;
};

Edge::Edge(unsigned int id_in, const Vertex vertex_1_in, const Vertex vertex_2_in)
    : SimplexBase(id_in), vertex_1(vertex_1_in), vertex_2(vertex_2_in)
{
}

/*
**************************FACE ********************************
*/
class Face : public SimplexBase
{
public:
    Face(unsigned int id_in, const Edge edge_1_in, const Edge edge_2_in, const Edge edge_3_in);
    ~Face() = default;
    void print() { std::cout << "Face " << this->get_id() << std::endl;}
    const std::vector<Edge> get_edges() const;
    const bool is_valid() const;
    const bool operator== (const Face &face_1) const;
    const bool operator!= (const Face &face_1) const;

private:
    const Edge &edge_1;
    const Edge &edge_2;
    const Edge &edge_3;

};

Face::Face(unsigned int id_in, const Edge edge_1_in, const Edge edge_2_in, const Edge edge_3_in)
    : SimplexBase(id_in), edge_1(edge_1_in), edge_2(edge_2_in), edge_3(edge_3_in)
{
}



/*
**************************TET ********************************
*/
class Tetrahedron : public SimplexBase
{
public:
    Tetrahedron(unsigned int id_in, const Face face_1_in, const Face face_2_in, const Face face_3_in, const Face face_4_in);
    ~Tetrahedron() = default;
    void print() { std::cout << "Tetrahedron " << this->get_id() << std::endl;}
    const std::vector<Face> get_faces() const;
    const bool is_valid() const;
    const bool operator== (const Tetrahedron &tetrahedron_1) const;
    const bool operator!= (const Tetrahedron &tetrahedron_1) const;

private:
    const Face &face_1;
    const Face &face_2;
    const Face &face_3;
    const Face &face_4;
};

Tetrahedron::Tetrahedron(unsigned int id_in, const Face face_1_in, const Face face_2_in, const Face face_3_in, const Face face_4_in)
    : SimplexBase(id_in), face_1(face_1_in), face_2(face_2_in), face_3(face_3_in), face_4(face_4_in)
{
}

// Path: include/TriangulationSimplex.h
#endif // THICKER_TRIANGULATION_H