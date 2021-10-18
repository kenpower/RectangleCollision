#include "pch.h"

#include "../RectangleCollision/Rectangle.h"

TEST(CollidesWithSame, Rectangle) {

	Rectangle a{ 0,0,1,1 };
	Rectangle b{ 0,0,1,1 };

	ASSERT_TRUE(a.collidesWith(b));
}

TEST(DoesNotCollidesOnLeft, Rectangle) {

	Rectangle a{ 0,0,1,1 };
	Rectangle b{ 2,0,1,1 };

	ASSERT_FALSE(a.collidesWith(b));
}

TEST(DoesNotCollidesOnRight, Rectangle) {

	Rectangle a{ 0,0,1,1 };
	Rectangle b{ 2,0,1,1 };

	ASSERT_FALSE(b.collidesWith(a));
}

TEST(DoesNotCollidesAbove, Rectangle) {

	Rectangle a{ 0,0,1,1 };
	Rectangle b{ 0,2,1,1 };

	ASSERT_FALSE(a.collidesWith(b));
}

TEST(DoesNotCollidesUnder, Rectangle) {

	Rectangle a{ 0,0,1,1 };
	Rectangle b{ 0,-2,1,1 };

	ASSERT_FALSE(a.collidesWith(b));
}

TEST(DoesNotCollidesDiagonal, Rectangle) {

	Rectangle a{ 0,0,1,1 };
	Rectangle b{ 2,2,1,1 };

	ASSERT_FALSE(a.collidesWith(b));
}

TEST(DoesCollidesDiagonalOverlap, Rectangle) {

	Rectangle a{ 0,0,2,2 };
	Rectangle b{ 2,2,2,2 };

	ASSERT_TRUE(a.collidesWith(b));
	ASSERT_TRUE(b.collidesWith(a));
}

TEST(DoesCollidesDiagonalInside, Rectangle) {

	Rectangle a{ 0,0,3,3 };
	Rectangle b{ 1,1,1,1 };

	ASSERT_TRUE(a.collidesWith(b));
	ASSERT_TRUE(b.collidesWith(a));
}