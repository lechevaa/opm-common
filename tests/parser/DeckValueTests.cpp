


#define BOOST_TEST_MODULE DeckValueTests
#include <boost/test/unit_test.hpp>

#include <opm/parser/eclipse/Parser/Parser.hpp>
#include <opm/parser/eclipse/Parser/ParserKeyword.hpp>
#include <opm/parser/eclipse/Parser/ParserKeywords/A.hpp>

#include <opm/parser/eclipse/Deck/DeckValue.hpp>
#include <opm/parser/eclipse/Deck/DeckKeyword.hpp>

using namespace Opm;

BOOST_AUTO_TEST_CASE(DeckValueTest) {

    DeckValue value0;

    BOOST_CHECK(value0.is<int>());
    BOOST_CHECK(!value0.is<std::string>());
    BOOST_CHECK_EQUAL( value0.get<int>(), 0);
    BOOST_CHECK_THROW( value0.get<std::string>(), std::invalid_argument);
    BOOST_CHECK_THROW( value0.get<double>(), std::invalid_argument);

    DeckValue value1(10);
    BOOST_CHECK(value1.is<int>());
    BOOST_CHECK(!value1.is<std::string>());
    BOOST_CHECK_EQUAL( value1.get<int>(), 10);

    DeckValue value2(10.0);
    BOOST_CHECK(value2.is<double>());
    BOOST_CHECK(!value2.is<std::string>());
    BOOST_CHECK_EQUAL( value2.get<double>(), 10);
    BOOST_CHECK_THROW( value2.get<std::string>(), std::invalid_argument);
    BOOST_CHECK_THROW( value2.get<int>(), std::invalid_argument);

    DeckValue value3("FUBHP");
    BOOST_CHECK(!value3.is<double>());
    BOOST_CHECK(value3.is<std::string>());
    BOOST_CHECK_EQUAL( value3.get<std::string>(), std::string("FUBHP"));
    BOOST_CHECK_THROW( value3.get<double>(), std::invalid_argument);
    BOOST_CHECK_THROW( value3.get<int>(), std::invalid_argument);


}