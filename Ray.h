
#ifndef __RAY_H
#define __RAY_H

#include "primitive.h"

typedef struct {
	
	double dist;
	
	primitive_t * primitive;
	
	vec_t intersection;
	
	vec_t normal;
	
	double u, v;
	
} intersect_t;

int cast_ray_triangle(vec_t * RayOri, vec_t * RayDir, triangle_t * tri, intersect_t * rtn);
#pragma acc routine(cast_ray_triangle) seq
int cast_ray_ellipsoid(vec_t * RayOri, vec_t * RayDir, ellipsoid_t * ellipsoid, intersect_t * rtn);
#pragma acc routine(cast_ray_ellipsoid) seq
int cast_ray_cuboid(vec_t * RayOri, vec_t * RayDir, cuboid_t * cuboid, intersect_t * rtn);
#pragma acc routine(cast_ray_cuboid) seq
int cast_ray_primitive(vec_t * RayOri, vec_t * RayDir, primitive_t * primitive, vec_t * vec_list, intersect_t * rtn);
#pragma acc routine(cast_ray_primitive) seq
int cast_ray_bvh(vec_t * RayOri, vec_t * RayDir, bvh_t * bvh, vec_t * vec_list, intersect_t * rtn);
#pragma acc routine(cast_ray_bvh) seq

void trace_ray(vec_t * RayOri, vec_t * RayRayDir, bvh_t * bvh, vec_t * vec_list, color_t * rtn);
#pragma acc routine(trace_ray) seq


unsigned int color_to_int(color_t color);
#pragma acc routine(color_to_int) seq


void render_image(camera_t Camera, model_t render_target, unsigned int * PixelBuffer);

#endif