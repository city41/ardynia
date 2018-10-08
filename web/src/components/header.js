import React from "react";
import { Link } from "gatsby";

import "./header.css";

const PAGES = ["help", "contact"];

const Header = ({ siteTitle }) => (
    <nav className="header">
        <ul>
            <li>
                <Link to="/">home</Link>
            </li>
            {PAGES.map(p => (
                <li>
                    <Link to={"/" + p}>{p}</Link>
                </li>
            ))}
        </ul>
    </nav>
);

export default Header;
