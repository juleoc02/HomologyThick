#include '../include/Simplices.h'
#include <cmath>

//*************************VERTICES********************************

TEST(VERTEX, GET_COORDINATES)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    std::vector<double> coordinates = {1.0, 2.0, 3.0};
    EXPECT_EQ(vertex_1.get_coordinates(), coordinates);
}

TEST(VERTEX, IS_VALID)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    EXPECT_EQ(vertex_1.is_valid(), true);
}

TEST(VERTEX, OPERATOR_EQUAL)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    Vertex vertex_2(1.0, 2.0, 3.0, 2);
    EXPECT_EQ(vertex_1 == vertex_2, true);
}

TEST(VERTEX, OPERATOR_NOT_EQUAL)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    Vertex vertex_2(1.0, 2.0, 3.0, 2);
    EXPECT_EQ(vertex_1 != vertex_2, false);
}

//*************************EDGES********************************

TEST(EDGE, GET_VERTICES)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    Vertex vertex_2(4.0, 5.0, 6.0, 2);
    Edge edge_1(1, vertex_1, vertex_2);
    std::vector<Vertex> vertices = {vertex_1, vertex_2};
    EXPECT_EQ(edge_1.get_vertices(), vertices);
}

TEST(EDGE, IS_VALID)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    Vertex vertex_2(4.0, 5.0, 6.0, 2);
    Edge edge_1(1, vertex_1, vertex_2);
    EXPECT_EQ(edge_1.is_valid(), true);
}

TEST(EDGE, IS_NOT_VALID)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    Vertex vertex_2(1.0, 2.0, 3.0, 2);
    Edge edge_1(1, vertex_1, vertex_2);
    EXPECT_EQ(edge_1.is_valid(), false);
}

TEST(EDGE, OPERATOR_EQUAL)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    Vertex vertex_2(4.0, 5.0, 6.0, 2);
    Edge edge_1(1, vertex_1, vertex_2);
    Edge edge_2(2, vertex_1, vertex_2);
    EXPECT_EQ(edge_1 == edge_2, true);
}

TEST(EDGE, OPERATOR_NOT_EQUAL)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    Vertex vertex_2(4.0, 5.0, 6.0, 2);
    Edge edge_1(1, vertex_1, vertex_2);
    Edge edge_2(2, vertex_1, vertex_2);
    EXPECT_EQ(edge_1 != edge_2, false);
}

//*************************FACES********************************

TEST(FACE, GET_EDGES)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    Vertex vertex_2(4.0, 5.0, 6.0, 2);
    Vertex vertex_3(7.0, 8.0, 9.0, 3);
    Edge edge_1(1, vertex_1, vertex_2);
    Edge edge_2(2, vertex_2, vertex_3);
    Edge edge_3(3, vertex_3, vertex_1);

    Face face_1(1, edge_1, edge_2, edge_3);
    std::vector<Edge> edges = {edge_1, edge_2, edge_3};
    EXPECT_EQ(face_1.get_edges(), edges);
}

TEST(FACE, IS_VALID)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    Vertex vertex_2(4.0, 5.0, 6.0, 2);
    Vertex vertex_3(7.0, 8.0, 9.0, 3);
    Edge edge_1(1, vertex_1, vertex_2);
    Edge edge_2(2, vertex_2, vertex_3);
    Edge edge_3(3, vertex_3, vertex_1);

    Face face_1(1, edge_1, edge_2, edge_3);
    EXPECT_EQ(face_1.is_valid(), true);
}

TEST(FACE, IS_NOT_VALID)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    Vertex vertex_2(4.0, 5.0, 6.0, 2);
    Vertex vertex_3(7.0, 8.0, 9.0, 3);
    Edge edge_1(1, vertex_1, vertex_2);
    Edge edge_2(2, vertex_2, vertex_3);
    Edge edge_3(3, vertex_2, vertex_3);

    Face face_1(1, edge_1, edge_2, edge_3);
    EXPECT_EQ(face_1.is_valid(), false);
}

TEST(FACE, OPERATOR_EQUAL)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    Vertex vertex_2(4.0, 5.0, 6.0, 2);
    Vertex vertex_3(7.0, 8.0, 9.0, 3);
    Edge edge_1(1, vertex_1, vertex_2);
    Edge edge_2(2, vertex_2, vertex_3);
    Edge edge_3(3, vertex_3, vertex_1);

    Face face_1(1, edge_1, edge_2, edge_3);
    Face face_2(2, edge_1, edge_2, edge_3);
    EXPECT_EQ(face_1 == face_2, true);
}  

TEST(FACE, OPERATOR_NOT_EQUAL)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    Vertex vertex_2(4.0, 5.0, 6.0, 2);
    Vertex vertex_3(7.0, 8.0, 9.0, 3);
    Edge edge_1(1, vertex_1, vertex_2);
    Edge edge_2(2, vertex_2, vertex_3);
    Edge edge_3(3, vertex_3, vertex_1);

    Face face_1(1, edge_1, edge_2, edge_3);
    Face face_2(2, edge_1, edge_2, edge_3);
    EXPECT_EQ(face_1 != face_2, false);
}

//*************************TETRAHEDRA********************************

TEST(TETRAHEDRON, GET_FACES)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    Vertex vertex_2(4.0, 5.0, 6.0, 2);
    Vertex vertex_3(7.0, 8.0, 9.0, 3);
    Vertex vertex_4(10.0, 11.0, 12.0, 4);
    Edge edge_1(1, vertex_1, vertex_2);
    Edge edge_2(2, vertex_2, vertex_3);
    Edge edge_3(3, vertex_3, vertex_1);
    Edge edge_4(4, vertex_1, vertex_4);
    Edge edge_5(5, vertex_2, vertex_4);
    Edge edge_6(6, vertex_3, vertex_4);
    Face face_1(1, edge_1, edge_2, edge_3);
    Face face_2(2, edge_1, edge_4, edge_5);
    Face face_3(3, edge_2, edge_5, edge_6);
    Face face_4(4, edge_3, edge_4, edge_6);
    Tetrahedron tetrahedron_1(1, face_1, face_2, face_3, face_4);

    std::vector<Face> faces = {face_1, face_2, face_3, face_4};
    EXPECT_EQ(tetrahedron_1.get_faces(), faces);
}

TEST(TETRAHEDRON, IS_VALID)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    Vertex vertex_2(4.0, 5.0, 6.0, 2);
    Vertex vertex_3(7.0, 8.0, 9.0, 3);
    Vertex vertex_4(10.0, 11.0, 12.0, 4);
    Edge edge_1(1, vertex_1, vertex_2);
    Edge edge_2(2, vertex_2, vertex_3);
    Edge edge_3(3, vertex_3, vertex_1);
    Edge edge_4(4, vertex_1, vertex_4);
    Edge edge_5(5, vertex_2, vertex_4);
    Edge edge_6(6, vertex_3, vertex_4);
    Face face_1(1, edge_1, edge_2, edge_3);
    Face face_2(2, edge_1, edge_4, edge_5);
    Face face_3(3, edge_2, edge_5, edge_6);
    Face face_4(4, edge_3, edge_4, edge_6);
    Tetrahedron tetrahedron_1(1, face_1, face_2, face_3, face_4);
    EXPECT_EQ(tetrahedron_1.is_valid(), true);
}

TEST(TETRAHEDRON, OPERATOR_EQUAL)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    Vertex vertex_2(4.0, 5.0, 6.0, 2);
    Vertex vertex_3(7.0, 8.0, 9.0, 3);
    Vertex vertex_4(10.0, 11.0, 12.0, 4);
    Edge edge_1(1, vertex_1, vertex_2);
    Edge edge_2(2, vertex_2, vertex_3);
    Edge edge_3(3, vertex_3, vertex_1);
    Edge edge_4(4, vertex_1, vertex_4);
    Edge edge_5(5, vertex_2, vertex_4);
    Edge edge_6(6, vertex_3, vertex_4);
    Face face_1(1, edge_1, edge_2, edge_3);
    Face face_2(2, edge_1, edge_4, edge_5);
    Face face_3(3, edge_2, edge_5, edge_6);
    Face face_4(4, edge_3, edge_4, edge_6);
    Tetrahedron tetrahedron_1(1, face_1, face_2, face_3, face_4);
    Tetrahedron tetrahedron_2(2, face_1, face_2, face_3, face_4);
    EXPECT_EQ(tetrahedron_1 == tetrahedron_2, true);
}

TEST(TETRAHEDRON, OPERATOR_NOT_EQUAL)
{
    Vertex vertex_1(1.0, 2.0, 3.0, 1);
    Vertex vertex_2(4.0, 5.0, 6.0, 2);
    Vertex vertex_3(7.0, 8.0, 9.0, 3);
    Vertex vertex_4(10.0, 11.0, 12.0, 4);
    Edge edge_1(1, vertex_1, vertex_2);
    Edge edge_2(2, vertex_2, vertex_3);
    Edge edge_3(3, vertex_3, vertex_1);
    Edge edge_4(4, vertex_1, vertex_4);
    Edge edge_5(5, vertex_2, vertex_4);
    Edge edge_6(6, vertex_3, vertex_4);
    Face face_1(1, edge_1, edge_2, edge_3);
    Face face_2(2, edge_1, edge_4, edge_5);
    Face face_3(3, edge_2, edge_5, edge_6);
    Face face_4(4, edge_3, edge_4, edge_6);
    Tetrahedron tetrahedron_1(1, face_1, face_2, face_3, face_4);
    Tetrahedron tetrahedron_2(2, face_1, face_2, face_3, face_4);
    EXPECT_EQ(tetrahedron_1 != tetrahedron_2, false);
}

