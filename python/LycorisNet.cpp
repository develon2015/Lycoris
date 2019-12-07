#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "lycoris.h"

namespace py = pybind11;

PYBIND11_MODULE(LycorisNet, m) {
    // m.doc() = "Description...";

    py::class_<LycorisNet::Lycoris>(m, "Lycoris")
            .def(py::init<uint32_t, uint32_t, uint32_t, const std::string &>(), py::arg("capacity"),
                 py::arg("inputDim"), py::arg("outputDim"), py::arg("mode"))
            .def("preheat", &LycorisNet::Lycoris::preheat, py::arg("nodes"), py::arg("connections"), py::arg("depths"))
            .def("evolve", &LycorisNet::Lycoris::evolve)
            .def("fit", &LycorisNet::Lycoris::fit)
            .def("fitAll", &LycorisNet::Lycoris::fitAll)
            .def("enrich", &LycorisNet::Lycoris::enrich)
            .def("compute", &LycorisNet::Lycoris::compute)
            .def("resize", &LycorisNet::Lycoris::resize)
            .def("openMemLimit", &LycorisNet::Lycoris::openMemLimit)
            .def("closeMemLimit", &LycorisNet::Lycoris::closeMemLimit)
            .def("import", &LycorisNet::Lycoris::import)
            .def("save", &LycorisNet::Lycoris::save)
            .def("setMutateArgs", &LycorisNet::Lycoris::setMutateArgs)
            .def("setMutateOdds", &LycorisNet::Lycoris::setMutateOdds)
            .def("setCpuCores", &LycorisNet::Lycoris::setCpuCores)
            .def("setLR", &LycorisNet::Lycoris::setLR)
            .def("getSize", &LycorisNet::Lycoris::getSize)
            .def("getInputNum", &LycorisNet::Lycoris::getInputNum)
            .def("getOutputNum", &LycorisNet::Lycoris::getOutputNum)
            .def("getCapacity", &LycorisNet::Lycoris::getCapacity)
            .def("getMode", &LycorisNet::Lycoris::getMode)
            .def("version", &LycorisNet::Lycoris::version);
}