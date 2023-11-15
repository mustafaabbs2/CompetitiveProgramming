#include <array>
#include <cmath>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

struct Point
{
    int id;
    double x, y, z;
};

struct OctreeNode
{
    Point* point;
    OctreeNode* children[8]; // 8 pointers
};

class Octree
{
public:
    Octree(int minX, int maxX, int minY, int maxY, int minZ, int maxZ)
    {
        root = nullptr;
        bounds[0] = minX;
        bounds[1] = maxX;
        bounds[2] = minY;
        bounds[3] = maxY;
        bounds[4] = minZ;
        bounds[5] = maxZ;
    }

    ~Octree() { clear(); }

    void clear() { root = nullptr; }

    void insert(Point* point)
    {
        if (root == nullptr)
            root = createNode();

        insertPoint(point, root, bounds[0], bounds[1], bounds[2], bounds[3],
                    bounds[4], bounds[5]);
    }

    void printTree()
    {
        OctreeNode* node = root;

        if (node == nullptr)
            return;

        std::queue<OctreeNode*> queue;
        queue.push(node);

        while (!queue.empty())
        {
            OctreeNode* current = queue.front();
            queue.pop(); // removes the front of the queue, you just used it
                         // above

            std::cout << "Point id: " << current->point->id << std::endl;

            for (size_t i = 0; i < 8; i++)
            {
                if (current->children[i] != nullptr)
                    queue.push(
                        current->children[i]); // adds to the end of the queue
            }
        }
    }

    // public API
    Point* findClosestNeighbour(double x, double y, double z)
    {
        auto minDistance = std::numeric_limits<double>::max();

        OctreeNode* node = root;
        Point* nearest = root->point;

        findClosestNeighbour(nearest, x, y, z, node, minDistance);
        return nearest;
    }

private:
    std::array<int, 6> bounds;
    OctreeNode* root;

    OctreeNode* createNode()
    {

        OctreeNode* node = new OctreeNode();

        for (size_t i = 0; i < 8; i++)
            node->children[i] = nullptr;

        node->point = nullptr;
        return node;
    }

    void insertPoint(Point* point, OctreeNode* node, double minX, double minY,
                     double minZ, double maxX, double maxY, double maxZ)
    {
        if (node->point == nullptr)
        {
            node->point = point;
            return;
        }

        double midX = (minX + maxX) / 2;
        double midY = (minY + maxY) / 2;
        double midZ = (minZ + maxZ) / 2;

        int octant = getOctant(point->x, point->y, point->z, midX, midY, midZ);

        if (node->children[octant] == nullptr)
            node->children[octant] = createNode();

        insertPoint(point, node->children[octant], (octant & 1) ? midX : minX,
                    (octant & 1) ? maxX : midX, (octant & 2) ? midY : minY,
                    (octant & 2) ? maxY : midY, (octant & 4) ? midZ : minZ,
                    (octant & 4) ? maxZ : midZ);
    }

    double findDistance(double x1, double y1, double z1, double x2, double y2,
                        double z2)
    {
        auto delx = pow(x1 - x2, 2);
        auto dely = pow(y1 - y2, 2);
        auto delz = pow(z1 - z2, 2);

        return sqrt(delx + dely + delz);
    }

    void findClosestNeighbour(
        Point*& nearest, double x, double y, double z, OctreeNode* node,
        double& minDistance) // passing node, will have to do it recursively
    {
        if (node == nullptr)
            return;

        auto distance = findDistance(node->point->x, node->point->y,
                                     node->point->z, x, y, z);

        if (distance < minDistance)
        {
            minDistance = distance;
            nearest = node->point;
        }

        // now, only search in octants the point is in
        //note - this is probably incorrect, bounds need to be updated
        auto midX = 0.5 * (bounds[0] + bounds[1]);
        auto midY = 0.5 * (bounds[2] + bounds[3]);
        auto midZ = 0.5 * (bounds[4] + bounds[5]);

        auto octant = getOctant(x, y, z, midX, midY, midZ);

        if (node->children[octant] != nullptr)
            findClosestNeighbour(nearest, x, y, z, node->children[octant],
                                 minDistance);

        // Check the neighboring octants if necessary
        for (int i = 0; i < 8; ++i)
        {
            if (node->children[i] != nullptr &&
                (node->children[i] != node->children[octant]))
            {
                double dx = x - midX;
                double dy = y - midY;
                double dz = z - midZ;
                double closestX = midX + ((i & 1) ? dx : -dx);
                double closestY = midY + ((i & 2) ? dy : -dy);
                double closestZ = midZ + ((i & 4) ? dz : -dz);

                if (findDistance(closestX, closestY, closestZ, x, y, z) <
                    minDistance)
                {
                    findClosestNeighbour(nearest, x, y, z, node->children[i],
                                         minDistance);
                }
            }
        }
    }
    // The idea is to set three bits of an int to certain values
    // Total number of combinations = 2^3 = 8 for 8 octants
    // 0000 0001 for +x //1
    // 0000 0010 for +y //2
    // 0000 0100 for +z //4
    // Note(this is a 1 byte representation..)
    int getOctant(double x, double y, double z, double midX, double midY,
                  double midZ)
    {
        int octant = 0;
        if (x > midX)
            octant |= 1;
        if (y > midY)
            octant |= 2;
        if (z > midZ)
            octant |= 4;

        return octant;
    }
};

int main()
{

    std::vector<Point*> points;
    points.push_back(new Point{1, 2.0, 3.0, 4.0});
    points.push_back(new Point{2, 2.1, 5.0, 7.0});
    points.push_back(new Point{3, 3.0, 3.0, 4.0});
    points.push_back(new Point{4, 3.0, 3.0, 4.0});
    points.push_back(new Point{5, 3.0, 3.0, 4.0});
    points.push_back(new Point{6, 3.0, 3.0, 4.0});
    points.push_back(new Point{7, 8.0, 3.0, 4.0});
    points.push_back(new Point{8, 2.0, 7.0, 6.0});
    points.push_back(new Point{9, 3.4, 1.0, 2.0});
    points.push_back(new Point{10, 3.2, 2.5, 2.3});
    points.push_back(new Point{11, 6.0, 3.9, 5.4});
    points.push_back(new Point{12, 5.0, 2.0, 4.6});

    Octree octree(-10, 10, -10, 10, -10, 10);

    for (auto point : points)
        octree.insert(point);

    auto nearest = octree.findClosestNeighbour(5.0, 2.0, 4.6);

    std::cout << "ID of the nearest point is: " << nearest->id << std::endl;

    octree.printTree();

    // Free memory, not RAII yet
    for (auto point : points)
        delete point;
}