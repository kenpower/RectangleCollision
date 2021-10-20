#include "pch.h"

#include "../RectangleCollision/Rectangle.h"

TEST(Rectangle, CollidesWithSame) {

	Rectangle a{ 0,0,1,1 };
	Rectangle b{ 0,0,1,1 };

	ASSERT_TRUE(a.collidesWith(b));
}

TEST(Rectangle, DoesNotCollidesOnLeft) {

	Rectangle a{ 0,0,1,1 };
	Rectangle b{ 2,0,1,1 };

	ASSERT_FALSE(a.collidesWith(b));
}

TEST(Rectangle, DoesNotCollidesOnRight) {

	Rectangle a{ 0,0,1,1 };
	Rectangle b{ 2,0,1,1 };

	ASSERT_FALSE(b.collidesWith(a));
}

TEST(Rectangle, DoesNotCollidesAbove) {

	Rectangle a{ 0,0,1,1 };
	Rectangle b{ 0,2,1,1 };

	ASSERT_FALSE(a.collidesWith(b));
}

TEST(Rectangle, DoesNotCollidesUnder) {

	Rectangle a{ 0,0,1,1 };
	Rectangle b{ 0,-2,1,1 };

	ASSERT_FALSE(a.collidesWith(b));
}

TEST(Rectangle, DoesNotCollidesDiagonal) {

	Rectangle a{ 0,0,1,1 };
	Rectangle b{ 2,2,1,1 };

	ASSERT_FALSE(a.collidesWith(b));
}

TEST(Rectangle, DoesCollidesDiagonalOverlap) {

	Rectangle a{ 0,0,2,2 };
	Rectangle b{ 2,2,2,2 };

	ASSERT_TRUE(a.collidesWith(b));
	ASSERT_TRUE(b.collidesWith(a));
}

TEST(Rectangle, DoesCollidesDiagonalInside) {

	Rectangle a{ 0,0,3,3 };
	Rectangle b{ 1,1,1,1 };

	ASSERT_TRUE(a.collidesWith(b));
	ASSERT_TRUE(b.collidesWith(a));
}