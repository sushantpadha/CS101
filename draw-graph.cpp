#include <simplecpp>

const int WINDOW_SIZE = 1000;
const int APOTHEM = WINDOW_SIZE / 2 - 10;
const int VMAX = 26;
const int EMAX = 325;

// Store character value, array of neighbours, number of neighbours, flag to see if
// number of neighbours is max
struct Vertex {
    char v;
    Vertex* nhbrs[VMAX - 1];  // Array of neighbors
    int num_nhbrs;            // Number of neighbors
    bool is_full;             // Flag to check if vertex has max neighbors
    int edge_idx = 0          // Index of next edge to draw (from 0 to num_nhbrs-1)

    Vertex(char _v) : v(_v), num_nhbrs(0), is_full(false) {}

    void addNeighbor(Vertex* neighbor) {
        if (num_nhbrs < VMAX - 1) {
            nhbrs[num_nhbrs++] = neighbor;
        } else {
            is_full = true;
        }
    }
};

// Store pointers to adjacent vertices
struct Edge {
    Vertex* v1;
    Vertex* v2;
    bool drawn = false;
};

// Store array of pointers to vertices, edges and numbers of vertices, edges
// respectively
class Graph {
public:
    Vertex* vertices[VMAX];  // Array of pointers to vertices
    int V;                   // Current number of vertices
    Edge* edges[EMAX];       // Array of pointers to edges
    int E;                   // Current number of edges

    Graph() : V(0), E(0) {}

    ~Graph() {
        // Delete allocated vertices
        for (int i = 0; i < V; i++) {
            delete vertices[i];
        }
        // Delete allocated edges
        for (int i = 0; i < E; i++) {
            delete edges[i];
        }
    }

    void addVertex(Vertex* vtx) {
        if (vtx == nullptr)
            return;  // Null check
        if (V >= VMAX)
            return;  // Check if graph is full

        vertices[V++] = vtx;
    }

    void addEdge(Edge* edge) {
        if (edge == nullptr || E >= EMAX)
            return;  // Check if graph or edge is full

        // Add edge
        edges[E++] = edge;

        // Add neighbors to the vertices
        edge->v1->addNeighbor(edge->v2);
        edge->v2->addNeighbor(edge->v1);
    }

    void addEdge(Vertex* v1, Vertex* v2) {
        if (v1 == nullptr || v2 == nullptr)
            return;  // Null check

        // Dynamically allocate the edge
        Edge* edge = new Edge{v1, v2};
        addEdge(edge);
    }

    void calculateGeometry(double& angle, double& side, double& radius) {
        angle = PI / 2 - PI / V;
        radius = APOTHEM / sin(angle);
        side = 2 * APOTHEM / tan(angle);
    }
};

void drawVertex() {
    right(45);
    // total rotation of 180 here
    for (int i = 0; i < 4; i++) {
        forward(3);
        forward(-3);
        right(45);
    }
    right(180);
    left(45);
}

// Recursive function to draw edges from one vertex to next until none left
void drawVertexEdges(Graph* g, Vertex* v) {
    if (v->edge_idx == v->num_nhbrs) return;
}

void drawGraph(Graph* g) {
    turtleSim("Draw Graph", WINDOW_SIZE, WINDOW_SIZE);
    penUp();
    forward(APOTHEM);
    right(90);
    forward(-side / 2);
    double angle, side, radius;
    g->calculateGeometry(angle, side, radius);
    penDown();

    for (int i = 0; i < g->V; i++) {
        if (g->vertices[i]) {
            drawVertex();
            drawVertexEdges(g, g->vertices[i]);
            forward(side);
            right(angle);
        }
    }
}

int main() {}
