#include "create_nasty_directed_named_vertices_graph.h"

#include <cassert>
#include "add_named_vertex.h"
#include "create_empty_directed_named_vertices_graph.h"
#include "save_named_vertices_graph_to_dot.h"
#include "load_directed_named_vertices_graph_from_dot.h"
#include "get_sorted_named_vertex_my_vertexes.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<boost::vertex_name_t,std::string>
>
create_nasty_directed_named_vertices_graph() noexcept
{
  auto g = create_empty_directed_named_vertices_graph();
  for (int i=0; i!=2; ++i) //Duplicate labels
  {
    //Normal
    add_named_vertex("A", g);
    //Spaces
    add_named_vertex("A B", g);
    //Spaces in end and front
    add_named_vertex(" A B", g);
    add_named_vertex("A B ", g);
    //Underscores
    add_named_vertex(" _A_B _ ", g);
    //Backslash
    add_named_vertex(" \\\\A\\B\\ ", g);
    //Quotes
    add_named_vertex(" \"A\"B\"\" ", g);
    //Commas
    add_named_vertex(" A,B,, ", g);
    //Escape sequence
    add_named_vertex("A\"];", g);
  }
  return g;
}


void create_nasty_directed_named_vertices_graph_test() noexcept
{
  {
    auto g = create_nasty_directed_named_vertices_graph();
    const std::string filename{
      "create_nasty_directed_named_vertices_graph_test.dot"
    };
    save_named_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_named_vertices_graph_from_dot(filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
    const auto a = get_sorted_vertex_names(g);
    const auto b = get_sorted_vertex_names(h);
    assert(a == b);
  }
  std::cout << __func__ << ": OK" << '\n';
}
