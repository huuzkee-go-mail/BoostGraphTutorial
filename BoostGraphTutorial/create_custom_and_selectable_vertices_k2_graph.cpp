#include "create_custom_and_selectable_vertices_k2_graph.h"

#include "create_custom_and_selectable_vertices_k2_graph.impl"

#include "create_custom_and_selectable_vertices_k2_graph_demo.impl"

#include <cassert>
#include <iostream>
#include "has_custom_vertex_with_my_vertex.h"
#include "save_custom_and_selectable_vertices_graph_to_dot.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"

void create_custom_and_selectable_vertices_k2_graph_test() noexcept
{
  //Basic tests
  {
    const auto g = create_custom_and_selectable_vertices_k2_graph();
    assert(boost::num_edges(g) == 1);
    assert(boost::num_vertices(g) == 2);
    assert(has_custom_vertex_with_my_custom_vertex(my_custom_vertex("A", "source" ,0.0, 0.0), g));
    assert(has_custom_vertex_with_my_custom_vertex(my_custom_vertex("B", "target" ,3.14, 3.14), g));
  }
  //Create the .dot and .svg of the 'create_custom_and_selectable_vertices_k2_graph' chapter
  {
    const auto g = create_custom_and_selectable_vertices_k2_graph();
    const std::string base_filename{"create_custom_and_selectable_vertices_k2_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_custom_and_selectable_vertices_graph_to_dot(g, dot_filename);
    convert_dot_to_svg(dot_filename, svg_filename);
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
  }
  create_custom_and_selectable_vertices_k2_graph_demo();
  std::cout << __func__ << ": OK" << '\n';

}
