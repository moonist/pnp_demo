/*
 * ObjectMesh.cpp
 *
 *  Created on: Apr 9, 2014
 *      Author: edgar
 */

#include "ObjectMesh.h"
#include "CsvReader.h"


// --------------------------------------------------- //
//                   TRIANGLE CLASS                    //
// --------------------------------------------------- //

/**  The custom constructor of the Triangle Class */
Triangle::Triangle(int id, cv::Point3f V0, cv::Point3f V1, cv::Point3f V2)
{
  id_ = id; v0_ = V0; v1_ = V1; v2_ = V2;
}

/**  The default destructor of the Class */
Triangle::~Triangle()
{
  // TODO Auto-generated destructor stub
}


// --------------------------------------------------- //
//                     RAY CLASS                       //
// --------------------------------------------------- //

/**  The custom constructor of the Ray Class */
Ray::Ray(cv::Point3f P0, cv::Point3f P1) {
  p0_ = P0; p1_ = P1;
}

/**  The default destructor of the Class */
Ray::~Ray()
{
  // TODO Auto-generated destructor stub
}


// --------------------------------------------------- //
//                 OBJECT MESH CLASS                   //
// --------------------------------------------------- //

/** The default constructor of the ObjectMesh Class */
ObjectMesh::ObjectMesh() : list_vertex_(0) , list_triangles_(0)
{
  id_ = 0;
  num_vertexs_ = 0;
  num_triangles_ = 0;
}

/** The default destructor of the ObjectMesh Class */
ObjectMesh::~ObjectMesh()
{
  // TODO Auto-generated destructor stub
}


/** Load a CSV file and fill the object mesh */
void ObjectMesh::load(const std::string path) {

  // Create the reader
  CsvReader csvReader(path);

  // Clear previous data
  list_vertex_.clear();
  list_triangles_.clear();

  // TODO: check path file to open different formats .ply .stl
  /*
   * if (path == .ply) then readPLY
   * if (path == .stl) then readSTL
   *
   */

  // Read from .ply file
  csvReader.readPLY(list_vertex_, list_triangles_);

  // Update mesh attributes
  num_vertexs_ = list_vertex_.size();
  num_triangles_ = list_triangles_.size();

}
