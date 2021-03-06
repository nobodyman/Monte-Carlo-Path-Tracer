//
// Created by Ficos on 26/03/2017.
//

#include <fstream>
#include <cstring>
#include "Scene.h"

void Scene::CornellBox(){
    if (!object_list.empty() || !light_list.empty()) {
        object_list.clear();
        light_list.clear();
    }

    Material plane_material = Material();

    // floor

    float high = 3;
    float low = -2;
    float back = 4;
    float left = -3;
    float right = 3;
    float x1 = left + 2.0f, z1 = 0.5f, x2 = right - 2.0f, z2 = 2.0f;


    Material triangle_light = Material();
    triangle_light.setEmission(WHITE);
    addObject(new Triangle(triangle_light, "triangle1",
                                       VecF(x1, high, z1), VecF(x1, high, z2), VecF(x2, high, z1)));
    addObject(new Triangle(triangle_light, "triangle2",
                                       VecF(x2, high, z1), VecF(x1, high, z2), VecF(x2, high, z2)));

    plane_material.setDiffuse_prob(1.0f);
    plane_material.setIntrinsic_color( WHITE * 0.2 );
    addObject(new Plane(plane_material, "floor", VecF(0, 1, 0), low));

    plane_material.setIntrinsic_color( GREEN );
    addObject(new Plane(plane_material, "left wall", VecF(1, 0, 0), left));

    plane_material.setIntrinsic_color( RED );
    addObject(new Plane(plane_material, "right wall", VecF(-1, 0, 0), -right));

    plane_material.setIntrinsic_color( WHITE );
    addObject(new Plane(plane_material, "back wall", VecF(0, 0, -1), -back));

    plane_material.setIntrinsic_color( WHITE * 0.8 );
    addObject(new Plane(plane_material, "ceiling", VecF(0, -1, 0), -high - 0.05f));

    Material sphere_material = Material();
    sphere_material.clear();
    sphere_material.setIntrinsic_color(WHITE);
    sphere_material.setRefraction_index(1.5f);
    sphere_material.setDiffuse_prob(0.0f);
    sphere_material.setRefraction_prob(0.0f);
    sphere_material.setReflection_prob(1.0f);
    sphere_material.setBase_reflection_rate(0.8f);
    float radius1 = 1.0f;
    addObject(new Sphere(sphere_material, "refractive sphere",
                         VecF(left + radius1 + 1, low + radius1, back - radius1 - 1), radius1));
//
//
    sphere_material.clear();
    sphere_material.setIntrinsic_color(WHITE);
    sphere_material.setDiffuse_prob(0.0f);
    sphere_material.setRefraction_prob(0.9f);
    sphere_material.setReflection_prob(0.1f);
    float radius2 = 1.0f;
    addObject(new Sphere(sphere_material, "transparent sphere", VecF(1.7f, -1.0f, 1.0f), radius2));
}

void Scene::castTest(std::string file, const TraceConfig& config){
    if (!object_list.empty() || !light_list.empty()) {
        object_list.clear();
        light_list.clear();
    }

    Material plane_material = Material();

    // floor

    float high = 5;
    float low = -2;
    float left = -3;
    float x1 = -2, z1 = -2.0f, x2 = 2, z2 = 0.0f;

    Material triangle_light = Material();
    triangle_light.setEmission(WHITE);
    addObject(new Triangle(triangle_light, "triangle1",
                           VecF(x1, high, z1), VecF(x1, high, z2), VecF(x2, high, z1)));
    addObject(new Triangle(triangle_light, "triangle2",
                           VecF(x2, high, z1), VecF(x1, high, z2), VecF(x2, high, z2)));


//    Material point_light = Material();
//    point_light.setEmission( WHITE);
//    addObject(new Sphere(point_light, "point light for test", VecF(2, high - 1.0f, -2.0f), 0.1f));
//    addObject(new Sphere(point_light, "point light for test", VecF(1, high - 1.0f, -2.0f), 0.1f));
//    addObject(new Sphere(point_light, "point light for test", VecF(-1, high - 1.0f, -2.0f), 0.1f));
//    addObject(new Sphere(point_light, "point light for test", VecF(-2, high - 1.0f, -2.0f), 0.1f));
//     walls
    plane_material.setDiffuse_prob(1.0f);
    plane_material.setIntrinsic_color( WHITE * 0.2 );
    addObject(new Plane(plane_material, "floor", VecF(0, 1, 0), low));

//    Material sphere_material = Material();
//    sphere_material.clear();
//    sphere_material.setIntrinsic_color(WHITE);
//    sphere_material.setRefraction_index(1.5f);
//    sphere_material.setDiffuse_prob(1.0f);
//    sphere_material.setRefraction_prob(0.0f);
//    sphere_material.setReflection_prob(0.0f);
//    sphere_material.setBase_reflection_rate(0.8f);
//    float radius1 = 1.0f;
//    addObject(new Sphere(sphere_material, "refractive sphere",
//                         VecF(0,0,4), radius1));
    addObject(new Mesh("mesh", file, config));
//    ObjLoader::loadObj(file, *this);
}

void Scene::MixTest(std::string file, const TraceConfig& config) {
    if (!object_list.empty() || !light_list.empty()) {
        object_list.clear();
        light_list.clear();
    }

    float high = 10;
    float low = 0;
    float back = 4;
    float left = -3 + 2 - 3;
    float right = 3 + 2 + 3;
    float x1 = left + 2.0f, z1 = -1.0f, x2 = right - 2.0f, z2 = 2.0f;

    Material plane_material = Material();
    Material triangle_light = Material();
    triangle_light.setEmission(WHITE * 3);
    addObject(new Triangle(triangle_light, "triangle1",
                           VecF(x1, high, z1), VecF(x1, high, z2), VecF(x2, high, z1)));
    addObject(new Triangle(triangle_light, "triangle2",
                           VecF(x2, high, z1), VecF(x1, high, z2), VecF(x2, high, z2)));

    plane_material.setDiffuse_prob(1.0f);
    plane_material.setIntrinsic_color( WHITE * 0.4 );
    plane_material.setTexture(new ImgTexture("../textures/ground.png", 40));
    addObject(new Plane(plane_material, "floor", VecF(0, 1, 0), low));
    plane_material.setTexture(NULL);

    plane_material.setIntrinsic_color( GREEN );
    addObject(new Plane(plane_material, "left wall", VecF(1, 0, 0), left));

    plane_material.setIntrinsic_color( RED );
    addObject(new Plane(plane_material, "right wall", VecF(-1, 0, 0), -right));

    plane_material.setIntrinsic_color( WHITE );
    plane_material.setTexture(new GridTexture(WHITE, BLACK, 0.5));
    addObject(new Plane(plane_material, "back wall", VecF(0, 0, -1), -back));
    plane_material.setTexture(NULL);

    plane_material.setIntrinsic_color( WHITE * 0.8 );
    addObject(new Plane(plane_material, "ceiling", VecF(0, -1, 0), -high - 0.05f));

    Material sphere_material = Material();
    sphere_material.clear();
    sphere_material.setIntrinsic_color(WHITE);
    sphere_material.setDiffuse_prob(0.0f);
    sphere_material.setRefraction_index(1.33f);
    sphere_material.setRefraction_prob(1.0f);
    sphere_material.setReflection_prob(0.00f);
    float radius1 = 1.6f;
    addObject(new Sphere(sphere_material, "diffuse sphere",
                         VecF(5, low + radius1, -2), radius1));


    addObject(new Mesh("mesh", file, config));
}

void Scene::ObjTest(std::string file, const TraceConfig& config) {
    if (!object_list.empty() || !light_list.empty()) {
        object_list.clear();
        light_list.clear();
    }

    float high = 10;
    float low = 0;
    float back = 4;
    float left = -3 - 3;
    float right = 3 + 3;
    float x1 = left + 2.0f, z1 = -1.0f, x2 = right - 2.0f, z2 = 2.0f;

    Material plane_material = Material();
    Material triangle_light = Material();
    triangle_light.setEmission(WHITE * 3);
    addObject(new Triangle(triangle_light, "triangle1",
                           VecF(x1, high, z1), VecF(x1, high, z2), VecF(x2, high, z1)));
    addObject(new Triangle(triangle_light, "triangle2",
                           VecF(x2, high, z1), VecF(x1, high, z2), VecF(x2, high, z2)));

    plane_material.setDiffuse_prob(1.0f);
    plane_material.setIntrinsic_color( WHITE * 0.4 );
    plane_material.setTexture(new ImgTexture("../textures/ground.png", 40));
    addObject(new Plane(plane_material, "floor", VecF(0, 1, 0), low));
    plane_material.setTexture(NULL);

    plane_material.setIntrinsic_color( GREEN );
    addObject(new Plane(plane_material, "left wall", VecF(1, 0, 0), left));

    plane_material.setIntrinsic_color( RED );
    addObject(new Plane(plane_material, "right wall", VecF(-1, 0, 0), -right));

    plane_material.setIntrinsic_color( WHITE );
    plane_material.setTexture(new GridTexture(WHITE, BLACK, 0.5));
    addObject(new Plane(plane_material, "back wall", VecF(0, 0, -1), -back));
    plane_material.setTexture(NULL);

    plane_material.setIntrinsic_color( WHITE * 0.8 );
    addObject(new Plane(plane_material, "ceiling", VecF(0, -1, 0), -high - 0.05f));

//    Material sphere_material = Material();
//    sphere_material.clear();
//    sphere_material.setIntrinsic_color(WHITE);
//    sphere_material.setDiffuse_prob(0.0f);
//    sphere_material.setRefraction_index(1.33f);
//    sphere_material.setRefraction_prob(1.0f);
//    sphere_material.setReflection_prob(0.00f);
//    float radius1 = 1.6f;
//    addObject(new Sphere(sphere_material, "diffuse sphere",
//                         VecF(5, low + radius1, -2), radius1));
//
//
    addObject(new Mesh("mesh", file, config));
}


void Scene::simpleTest() {
    if (!object_list.empty() || !light_list.empty()) {
        object_list.clear();
        light_list.clear();
    }
    float high = 10;
    float low = 0;
    float back = 4;
    float left = -3 + 2 - 3;
    float right = 3 + 2 + 3;
    float x1 = left + 2.0f, z1 = -1.0f, x2 = right - 2.0f, z2 = 2.0f;

    Material plane_material = Material();
    Material triangle_light = Material();
    triangle_light.setEmission(WHITE);
    addObject(new Triangle(triangle_light, "triangle1",
                           VecF(x1, high, z1), VecF(x1, high, z2), VecF(x2, high, z1)));
    addObject(new Triangle(triangle_light, "triangle2",
                           VecF(x2, high, z1), VecF(x1, high, z2), VecF(x2, high, z2)));

    plane_material.setDiffuse_prob(1.0f);
    plane_material.setIntrinsic_color( WHITE * 0.4 );
    plane_material.setTexture(new ImgTexture("../textures/ground.png", 40));
    addObject(new Plane(plane_material, "floor", VecF(0, 1, 0), low));

    plane_material.setTexture(NULL);
    plane_material.setIntrinsic_color( GREEN );
    addObject(new Plane(plane_material, "left wall", VecF(1, 0, 0), left));

    plane_material.setIntrinsic_color( RED );
    addObject(new Plane(plane_material, "right wall", VecF(-1, 0, 0), -right));

    plane_material.setIntrinsic_color( WHITE );
    addObject(new Plane(plane_material, "back wall", VecF(0, 0, -1), -back));

    plane_material.setIntrinsic_color( WHITE * 0.8 );
    plane_material.setTexture(NULL);
    addObject(new Plane(plane_material, "ceiling", VecF(0, -1, 0), -high - 0.05f));

    Material sphere_material = Material();
    sphere_material.clear();
    sphere_material.setIntrinsic_color( CYAN );
    sphere_material.setDiffuse_prob(1.0f);
    sphere_material.setRefraction_index(1.33f);
    sphere_material.setRefraction_prob(0.0f);
    sphere_material.setReflection_prob(0.0f);
    float radius1 = 1.6f;
    addObject(new Sphere(sphere_material, "diffuse sphere",
                         VecF(5, low + radius1, -2), radius1));
}
