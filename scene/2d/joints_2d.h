/*************************************************************************/
/*  joints_2d.h                                                          */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                    http://www.godotengine.org                         */
/*************************************************************************/
/* Copyright (c) 2007-2015 Juan Linietsky, Ariel Manzur.                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/
#ifndef JOINTS_2D_H
#define JOINTS_2D_H


#include "node_2d.h"

class Joint2D : public Node2D {

	OBJ_TYPE(Joint2D,Node2D);

	RID joint;

	NodePath a;
	NodePath b;
	real_t bias;


protected:

	void _update_joint();

	void _notification(int p_what);
	virtual RID _configure_joint()=0;

	static void _bind_methods();
public:

	void set_node_a(const NodePath& p_node_a);
	NodePath get_node_a() const;

	void set_node_b(const NodePath& p_node_b);
	NodePath get_node_b() const;

	void set_bias(real_t p_bias);
	real_t get_bias() const;

	RID get_joint() const { return joint; }
	Joint2D();

};


class PinJoint2D : public Joint2D {

	OBJ_TYPE(PinJoint2D,Joint2D);

protected:

	void _notification(int p_what);
	virtual RID _configure_joint();
public:



	PinJoint2D();
};

class GrooveJoint2D : public Joint2D {

	OBJ_TYPE(GrooveJoint2D,Joint2D);

	real_t length;
	real_t initial_offset;

protected:

	void _notification(int p_what);
	virtual RID _configure_joint();
	static void _bind_methods();
public:

	void set_length(real_t p_length);
	real_t get_length() const;

	void set_initial_offset(real_t p_initial_offset);
	real_t get_initial_offset() const;

	GrooveJoint2D();
};

class DampedSpringJoint2D : public Joint2D {

	OBJ_TYPE(DampedSpringJoint2D,Joint2D);

	real_t stiffness;
	real_t damping;
	real_t rest_length;
	real_t length;

protected:

	void _notification(int p_what);
	virtual RID _configure_joint();
	static void _bind_methods();
public:

	void set_length(real_t p_length);
	real_t get_length() const;

	void set_rest_length(real_t p_rest_length);
	real_t get_rest_length() const;

	void set_damping(real_t p_damping);
	real_t get_damping() const;

	void set_stiffness(real_t p_stiffness);
	real_t get_stiffness() const;

	DampedSpringJoint2D();
};


#endif // JOINTS_2D_H
