#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Circle.h"
#include "Rectangle.h"
#include "ShapeProcessor.h"

// Circle Test

Test(CircleTest, CorrectName) {
    Circle c(5.0);
    EXPECT_EQ(c.getName(), "Circle");
}

Test(CircleTest, CorrectArea) {
    Circle c(5.0);
    EXPECT_NEAR(c.getArea(), 78.539, 0.001);
}

Test(CircleTest, CorrectPerimeter) {
    Circle c(5.0);
    EXPECT_NEAR(c.getPerimeter(), 31.415, 0.001);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_NEAR(c.getArea(), 0.0, 0.001);
    EXPECT_NEAR(c.getPerimeter(), 0.0, 0.001);
}

// Rectangle Test

TEST(RectangleTest, CorrectName) {
    Rectangle r(4.0, 6.0);
    EXPECT_EQ(r.getName(), "Rectangle");
}

TEST(RectangleTest, CorrectArea) {
    Rectangle r(4.0, 6.0);
    EXPECT_NEAR(r.getArea(), 24.0, 0.001);
}

TEST(RectangleTest, CorrectPerimeter) {
    Rectangle r(4.0, 6.0);
    EXPECT_NEAR(r.getPerimeter(), 20.0, 0.001);
}

TEST(RectangleTest, SquareShape) {
    Rectangle r(5.0, 5.0);
    EXPECT_NEAR(r.getArea(), 25.0, 0.001);
    EXPECT_NEAR(r.getPerimeter(), 20.0, 0.001);
}

// ShapeProcessor Tests

TEST(ShapeProcessorTest, CreatesCircle) {
    ShapeProcessor processor;
    Shape* shape = processor.createShape("Circle", 5.0);
    ASSERT_NE(shape, nullptr);
    EXPECT_EQ(shape->getName(), "Circle");
    delete shape;
}

TEST(ShapeProcessorTest, CreatesRectangle) {
    ShapeProcessor processor;
    Shape* shape = processor.createShape("Rectangle", 4.0, 6.0);
    ASSERT_NE(shape, nullptr);
    EXPECT_EQ(shape->getName(), "Rectangle");
    delete shape;
}

TEST(ShapeProcessorTest, UnknownShape) {
    ShapeProcessor processor;
    Shape* shape = processor.createShape("Triangle", 5.0);
    EXPECT_EQ(shape, nullptr);
    delete shape;
}

//Mock Class (as Shapeprocessor depends on IShape)


