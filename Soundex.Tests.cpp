#include <gtest/gtest.h>
#include "Soundex.h"
 
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
    char soundex[5];
    generateSoundex("AX", soundex);
    ASSERT_STREQ(soundex, "A200");
}
 
TEST(SoundexTestsuite, RetainsSoleLetterOfOneLetterWord) {
    char soundex[5];
    generateSoundex("A", soundex);
    ASSERT_STREQ(soundex, "A000");
}
 
TEST(SoundexTestsuite, PadsWithZerosToEnsureThreeDigits) {
    char soundex[5];
    generateSoundex("N", soundex);
    ASSERT_STREQ(soundex, "N000");
}
 
TEST(SoundexTestsuite, CombinesDuplicateEncodingsSeparatedByVowels) {
    char soundex[5];
    generateSoundex("Ajkgd", soundex);
    ASSERT_STREQ(soundex, "A100");
}
 
TEST(SoundexTestsuite, UppercasesFirstLetter) {
    char soundex[5];
    generateSoundex("abcd", soundex);
    ASSERT_STREQ(soundex, "A123");
}
 
TEST(SoundexTestsuite, IgnoresCaseWhenEncodingConsonants) {
    char soundex[5];
    generateSoundex("BOLD", soundex);
    ASSERT_STREQ(soundex, "B123");
}
 
TEST(SoundexTestsuite, HandlesEmptyString) {
    char soundex[5];
    generateSoundex("", soundex);
    ASSERT_STREQ(soundex, "");
}
 
TEST(SoundexTestsuite, HandlesNullString) {
    char soundex[5];
    generateSoundex(nullptr, soundex);
    ASSERT_STREQ(soundex, "");
}
 
TEST(SoundexTestsuite, CombinesDuplicateEncodingsWithHAndWInBetween) {
    char soundex[5];
    generateSoundex("Aircondition", soundex);
    ASSERT_STREQ(soundex, "A520");
}
 
TEST(SoundexTestsuite, CombinesDuplicateEncodingsWithHAndWInBetween2) {
    char soundex[5];
    generateSoundex("bghtc", soundex);
    ASSERT_STREQ(soundex, "T520");
}
 
TEST(SoundexTestsuite, StopsAtThreeDigits) {
    char soundex[5];
    generateSoundex("Winidea", soundex);
    ASSERT_STREQ(soundex, "W150");
}
