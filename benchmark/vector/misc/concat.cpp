//
// immer - immutable data structures for C++
// Copyright (C) 2016, 2017 Juan Pedro Bolivar Puente
//
// This file is part of immer.
//
// immer is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// immer is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with immer.  If not, see <http://www.gnu.org/licenses/>.
//

#include "benchmark/vector/concat.hpp"

#include <immer/flex_vector.hpp>
#include <immer/flex_vector_transient.hpp>
#include <immer/heap/gc_heap.hpp>
#include <immer/refcount/no_refcount_policy.hpp>
#include <immer/refcount/unsafe_refcount_policy.hpp>

#if IMMER_BENCHMARK_LIBRRB
extern "C" {
#define restrict __restrict__
#include <rrb.h>
#undef restrict
}
#endif

#if IMMER_BENCHMARK_LIBRRB
NONIUS_BENCHMARK("librrb", benchmark_concat_librrb(make_librrb_vector))
NONIUS_BENCHMARK("librrb/F", benchmark_concat_librrb(make_librrb_vector_f))
NONIUS_BENCHMARK("i/librrb", benchmark_concat_incr_librrb(make_librrb_vector))
#endif

NONIUS_BENCHMARK("flex/4B", benchmark_concat<immer::flex_vector<unsigned,def_memory,4>>())
NONIUS_BENCHMARK("flex/5B", benchmark_concat<immer::flex_vector<unsigned,def_memory,5>>())
NONIUS_BENCHMARK("flex/6B", benchmark_concat<immer::flex_vector<unsigned,def_memory,6>>())
NONIUS_BENCHMARK("flex/GC", benchmark_concat<immer::flex_vector<unsigned,gc_memory,5>>())
NONIUS_BENCHMARK("flex_s/GC", benchmark_concat<immer::flex_vector<std::size_t,gc_memory,5>>())
NONIUS_BENCHMARK("flex/NO", benchmark_concat<immer::flex_vector<unsigned,basic_memory,5>>())
NONIUS_BENCHMARK("flex/UN", benchmark_concat<immer::flex_vector<unsigned,unsafe_memory,5>>())

NONIUS_BENCHMARK("flex/F/5B", benchmark_concat<immer::flex_vector<unsigned,def_memory,5>,push_front_fn>())
NONIUS_BENCHMARK("flex/F/GC", benchmark_concat<immer::flex_vector<unsigned,gc_memory,5>,push_front_fn>())
NONIUS_BENCHMARK("flex_s/F/GC", benchmark_concat<immer::flex_vector<std::size_t,gc_memory,5>,push_front_fn>())

NONIUS_BENCHMARK("i/flex/GC", benchmark_concat_incr<immer::flex_vector<unsigned,gc_memory,5>>())
NONIUS_BENCHMARK("i/flex_s/GC", benchmark_concat_incr<immer::flex_vector<std::size_t,gc_memory,5>>())
NONIUS_BENCHMARK("i/flex/5B", benchmark_concat_incr<immer::flex_vector<unsigned,def_memory,5>>())
NONIUS_BENCHMARK("i/flex/UN", benchmark_concat_incr<immer::flex_vector<unsigned,unsafe_memory,5>>())

NONIUS_BENCHMARK("m/flex/GC", benchmark_concat_incr_mut<immer::flex_vector<unsigned,gc_memory,5>>())
NONIUS_BENCHMARK("m/flex_s/GC", benchmark_concat_incr_mut<immer::flex_vector<std::size_t,gc_memory,5>>())
