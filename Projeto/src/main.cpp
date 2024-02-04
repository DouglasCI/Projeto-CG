#include "../include/obj.hpp"
#include "../include/sphere.hpp"
#include "../include/triangle.hpp"
#include "../include/hittable_list.hpp"
#include "../include/camera.hpp"
#include "../include/material.hpp"

int main() {
    // ============= World ============= //
    hittable_list world;

    // ============= Materials ============= //
    auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    auto material_sphere1 = make_shared<metal>(color(0.8, 0.3, 0.2), 0.1);
    auto material_sphere2 = make_shared<dielectric>(2.0);
    auto material_cube = make_shared<metal>(color(0.2, 0.6, 0.8), 0.3);

    // ============= Objects ============= //
    auto ground = make_shared<obj>("../input/big_cube.obj", material_ground);
    (ground.get())->move(vec3(0, -101, 0)); //change initial position
    auto sphere1 = make_shared<sphere>(point3(10, 0, 0), 1, material_sphere1);
    auto sphere2 = make_shared<sphere>(point3(3, 0, 0), 1, material_sphere2);
    auto cube1 = make_shared<obj>("../input/small_cube.obj", material_cube);
    (cube1.get())->move(vec3(-4, 0, 0)); //change initial position

    world.add(ground);
    world.add(sphere1);
    world.add(sphere2);
    world.add(cube1);

    // ============= Camera ============= //
    camera cam1;
    cam1.img_width = 480;
    cam1.samples_per_pixel = 80;
    cam1.max_depth = 40;
    cam1.look_from = point3(2, 0, 8);
    cam1.look_at = point3(0, 0, 0);

    // ============= Animation proccess ============= //
    int num_frames = 5 * 9; //number of frames (our time unit)
    int t = num_frames / 3; 
    vec3 camera_moviment = vec3(0, 2, -2);
    vec3 moviment1 = vec3(-5, 0, 0);
    vec3 velocity = moviment1 / t;
    for (int i = 0; i < t; ++i) {
        stringstream ss;
        ss << "../images/frame" << i << ".png";
        ss >> cam1.path;

        // Sphere1 moves with constant velocity towards cube1
        (sphere1.get())->move(moviment1 / t);

        // Camera movement
        cam1.look_from += camera_moviment / num_frames;
        cam1.render(world);
    }

    vec3 acceleration = -velocity / t;
    vec3 previous_moviment2 = vec3();
    for (int i = 1; i <= t; ++i) {
        stringstream ss;
        ss << "../images/frame" << i + t - 1 << ".png";
        ss >> cam1.path;

        // Sphere1 hits sphere2 and moves decelerating in the opposite direction
        vec3 moviment2 = velocity*i + (acceleration*i*i / 2);
        (sphere1.get())->move(-(moviment2 - previous_moviment2));
        previous_moviment2 = moviment2;

        // Sphere2 moves with constant velocity towards cube1
        (sphere2.get())->move(moviment1 / t);

        // Camera movement
        cam1.look_from += camera_moviment / num_frames;
        cam1.render(world);
    }

    vec3 previous_moviment3 = vec3();
    for (int i = 0; i < t; ++i) {
        stringstream ss;
        ss << "../images/frame" << i + 2*t << ".png";
        ss >> cam1.path;

        // Sphere2 hits cube1 and moves decelerating in the opposite direction
        vec3 moviment3 = velocity*i + (acceleration*i*i / 2);
        (sphere2.get())->move(-(moviment3 - previous_moviment3));
        previous_moviment3 = moviment3;

        // Camera movement
        cam1.look_from += camera_moviment / num_frames;
        cam1.render(world);
    }
}
