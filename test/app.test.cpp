// SPDX-FileCopyrightText: 2026 Klaus Reimer <k@ailis.de>
// SPDX-License-Identifier: MIT

#include "app.hpp"

#include <sstream>

#include <kaycxx/assert.hpp>
#include <kaycxx/test.hpp>

using namespace kaycxx::assert;
using namespace kaycxx::test;

suite("app") {
    it("prints the sum", [] {
        auto output = std::ostringstream();
        auto error_output = std::ostringstream();

        auto const exit_code = app({ "app-template", "1", "2" }, output, error_output);

        assert_equal(exit_code, 0);
        assert_equal(output.str(), "3\n");
        assert_equal(error_output.str(), "");
    });
}
